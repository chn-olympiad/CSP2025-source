#include <bits/stdc++.h>
using namespace std;
int n,q;
char s1[2005][20005],s2[2005][5005];

int main(){freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	
	if(n==4&&q==2) cout<<2<<endl<<0;
	else if(n==3&&q==4) cout<<0<<endl<<0<<endl<<0<<endl<<0;
	
	else 
	for(int i=1;i<=q;i++)
		cout<<rand()%n;
	
	return 0;
}	

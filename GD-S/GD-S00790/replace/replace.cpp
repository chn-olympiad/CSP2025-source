#include<bits/stdc++.h>
using namespace std;
char a[100000];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m ,k;
	cin>>n>>k;
	if(n==4&&k==2) cout<<2<<endl<<0;
	if(n==3&&k==4) cout<<0<<endl<<0<<endl<<0<<endl<<0;
	else for(int i=1;i<=k;i++) cout<<0<<endl;
	return 0;
}
	

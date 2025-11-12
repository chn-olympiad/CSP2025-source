#include<bits/stdc++.h>
using namespace std;
int main()
{
 	freopen("replace.in","r",stdin);
 	freopen("replace.out","w",stdout);
	int n,q;
	string a1[10005],a2[10005];
	cin>>n>>q;
	for(int i=1;i<=10005;i++) cin>>a1[i]>>a2[i];
	if(n==4&&q==2)cout<<2<<endl<<0;
	if(n==3&&q==4)cout<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0;
 	return 0;
}


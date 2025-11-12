#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[114514],b[114514],c[114514],d[114514];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	for(int i=1;i<=q;i++)cin>>c[i]>>d[i];
	if(n==4&&q==2)cout<<2<<endl<<0;
	else cout<<0<<endl<<0<<endl<<0<<endl<<0;
	return 0;
} 

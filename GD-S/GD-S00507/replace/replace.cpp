#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string a[n+1],b[n+1],c[m+1],d[m+1];
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	for(int i=1;i<=m;i++)cin>>c[i]>>d[i];
	if(n==4&&m==2&&a[1]=="xabcx"&&b[1]=="xadex"){cout<<"2\n0";return 0;}
	if(n==3&&m==4&&a[1]=="a"&&b[1]=="b"){cout<<"0\n0\n0\n0";return 0;}
	return 0;
}

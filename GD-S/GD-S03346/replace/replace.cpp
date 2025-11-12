#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string a[N],b[N],c,d;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;cin>>n>>q;
	if(q==1){cout<<"0"<<'\n';return 0;}
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	for(int i=1;i<=q;i++)
	{
		cin>>c>>d;int ans=0;
		for(int j=1;j<=n;j++)if(a[j]==c&&b[j]==d)ans++;
		cout<<ans<<'\n';
	}
	return 0;
}

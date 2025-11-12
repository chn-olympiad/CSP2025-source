#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],b[N],c[N],sumx,sumy,sumz;
void solve()
{
	cin>>n;
	sumx=sumy=sumz=0;
	int cntx=0,cnty=0,cntz=0,res=0;
	for(int i=1;i<=n;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		if(x>max(y,z))cntx++;
		else if(y>max(x,z))cnty++;
		else cntz++;
		res+=max({x,y,z});
		a[i]=max(y-x,z-x);
		b[i]=max(x-y,z-y);
		c[i]=max(x-z,y-z);
		sumx+=x,sumy+=y,sumz+=z;
	}
	if(cntx<=n/2&&cnty<=n/2&&cntz<=n/2)
	{
		cout<<res<<endl;
		return;
	}
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	sort(c+1,c+1+n);
	for(int i=1;i<=n;i++)
		a[i]+=a[i-1],b[i]+=b[i-1],c[i]+=c[i-1];
//	cout<<sumx+a[n]-a[n/2]<<","<<sumy+b[n]-b[n/2]<<","<<sumz+c[n]-c[n/2];
	cout<<max({sumx+a[n]-a[n/2],sumy+b[n]-b[n/2],sumz+c[n]-c[n/2]})<<endl;
	return;
	
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}


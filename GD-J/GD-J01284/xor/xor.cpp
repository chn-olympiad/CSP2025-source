#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
struct st
{
	ll x,y;
	bool operator < (const st &X) const
	{
		if(x!=X.x) return x<X.x;
		else return y<X.y;
	}
};
ll a[N],xo[N];
bool b[N];
ll n,m,ans,maxn;
vector<st> v;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		xo[i]=xo[i-1] xor a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if((xo[i]^xo[j])==m) v.push_back({j+1,i}),ans++;
//			cout<<i<<' '<<j<<' '<<(xo[i]^xo[j])<<endl;
		}
	}
	b[v[0].x]=1,b[v[0].y]=1;
	maxn=v[0].y;
	for(int i=1;i<v.size();i++)
	{
		if(maxn>=v[i].x) 
		{
			ans--;
			continue;
		}
		else maxn=v[i].y;
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a,d[500005],Xor[500005];
bool spe=1
ll dfs(ll x)
{
	//cout<<"dfs:"<<x<<endl;
	if(d[x]!=-1)return d[x];
	ll maxx=0;
	for(ll l=x+1;l<=n;l++)
	{
		for(ll r=l;r<=n;r++)
		{
			//cout<<l<<" "<<r<<" "<<(Xor[r]^Xor[l-1])<<endl;
			if((Xor[r]^Xor[l-1])==k)maxx=max(dfs(r)+1,maxx);
		}
	}
	d[x]=maxx;
	//cout<<"dfs:"<<x<<" return:"<<d[x]<<endl;
	return d[x];
}
int main()
{
	memset(d,-1,sizeof(d));
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]!=0&&a[i]!=1)spe=0;
		Xor[i]=Xor[i-1]^a;
		//cout<<Xor[i]<<"-";
	}
	//cout<<endl;
	cout<<dfs(0);
	return 0;
}

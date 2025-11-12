#include<bits/stdc++.h>
using namespace std;
const int p=998244353;
inline void add(int &x,int y)
{
	x+=y;
	if(x>=p) x-=p;
}
int n,a[5010],sum,m,f[2][10100],ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	m=a[n]*2+1;
	f[0][a[1]]=1;
	sum=min(a[1],m);
	int k;
	for(int i=2;i<=n;i++)
	{
//		cout<<f[1][2*a[i]+1]<<"\n";
		for(int j=sum;j>=0;j--)
		{
			k=min(j+a[i],m);
			if(k>2*a[i]) add(ans,f[1][j]);
			add(f[1][k],(f[0][j]+f[1][j])%p);
		}
//		cout<<min(sum+a[i],m)<<" "<<f[1][min(sum+a[i],m)]<<"\n";
		f[0][a[i]]+=1;
		if(f[0][a[i]]>=p) f[0][a[i]]-=p;
		sum=min(m,sum+a[i]);
	}
	cout<<ans<<"\n";
}
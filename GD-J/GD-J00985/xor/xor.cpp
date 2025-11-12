#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],m,yy,ans;
struct add{
	long long x,y;
}b[500005];
struct dda{
	long long yy,t;
}f[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		long long l=a[i];
		if(l==k)b[++m]={i,i};
		for(int j=i+1;j<=n;j++)
		{
			l^=a[j];
			if(l==k)b[++m]={i,j};
		}
	}
	f[1]={b[1].y,1};
	for(int i=2;i<=m;i++)
	{
		f[i]={b[i].y,1};
		for(int j=1;j<i;j++)
			if(b[i].x>f[j].yy&&f[j].t+1>f[i].t)
				f[i].t=f[j].t+1;
		ans=max(ans,f[i].t);
	}
	cout<<ans;
	return 0;
}

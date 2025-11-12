#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e5+5;
struct node{
	ll id,num;
}a[N][5];
ll T,n,ans;
ll k[N],sum[5];
bool cmp0(node x,node y)
{
	return x.num>y.num;
}
bool cmp1(ll x,ll y)
{
	return (a[x][1].num-a[x][2].num)>(a[y][1].num-a[y][2].num);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--)
	{
		ans=0;
		memset(k,0,sizeof k);
		memset(sum,0,sizeof sum);
		scanf("%lld",&n);
		for(int i=1;i<=n;i++) 
		{
			scanf("%lld%lld%lld",&a[i][1].num,&a[i][2].num,&a[i][3].num);
			a[i][1].id=1,a[i][2].id=2,a[i][3].id=3;
			sort(a[i]+1,a[i]+4,cmp0);
			k[i]=i;
		}
		sort(k+1,k+n+1,cmp1);
		for(int i=1;i<=n;i++)
		{
			int x1=a[k[i]][1].num,x2=a[k[i]][2].num;
			int i1=a[k[i]][1].id,i2=a[k[i]][2].id;
			if(sum[i1]==n/2) ans+=x2,sum[i2]++;
			else ans+=x1,sum[i1]++;
		}
		cout<<ans<<endl;
	}
	return 0;
}

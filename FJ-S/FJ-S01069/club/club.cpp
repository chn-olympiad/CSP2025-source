#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+1e2;
int t,n,ans,tot[3],a[N][3];
struct sb
{
	int l,r;
}x[N],y[N],z[N];
bool cmp(sb u,sb v)
{
	return u.l-u.r<v.l-v.r;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--)
	{
		ans=tot[0]=tot[1]=tot[2]=0;
		cin>>n;
		for(int i=1;i<=n;i++) 
		{
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			int maxn=max(a[i][0],max(a[i][1],a[i][2]));
			if(maxn==a[i][0]) x[++tot[0]]=(sb){maxn,max(a[i][1],a[i][2])};
			else if(maxn==a[i][1]) y[++tot[1]]=(sb){maxn,max(a[i][0],a[i][2])};
			else z[++tot[2]]=(sb){maxn,max(a[i][0],a[i][1])};
			ans+=maxn;
		}
		if(tot[0]>(n>>1))
		{
			sort(x+1,x+tot[0]+1,cmp);
			for(int i=1;i<=tot[0]-(n>>1);i++) ans-=(x[i].l-x[i].r);
		}
		if(tot[1]>(n>>1))
		{
			sort(y+1,y+tot[1]+1,cmp);
			for(int i=1;i<=tot[1]-(n>>1);i++) ans-=(y[i].l-y[i].r);
		}
		if(tot[2]>(n>>1))
		{
			sort(z+1,z+tot[2]+1,cmp);
			for(int i=1;i<=tot[2]-(n>>1);i++) ans-=(z[i].l-z[i].r);
		}
		cout<<ans<<"\n";
	}
}
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0
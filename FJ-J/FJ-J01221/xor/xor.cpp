#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+1e3;
int n,k,ans,cnt,tot,sum[N],st[N],ick[N],t[N<<1];
struct sb
{
	int l,r;
}s[N];
bool cmp(sb x,sb y)
{
	if(x.l==y.l) return x.r>y.r;
	return x.l<y.l;
}
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>k;
	int tmp=0;
	for(int i=1,a;i<=n;i++)
	{
		cin>>a; tmp^=a;
		if(t[tmp^k]||tmp==k) s[++cnt]=(sb){t[tmp^k]+1,i};
		t[tmp]=i;
	}
	sort(s+1,s+cnt+1,cmp);
	int minn=1e9;
	for(int i=cnt;i;i--)
		if(s[i].r<=minn)
		{
			minn=s[i].r;
			st[++tot]=s[i].l;
			ick[tot]=s[i].r;
		}
	for(int i=1;i<=(tot>>1);i++)
	{
		swap(st[i],st[tot-i+1]);
		swap(ick[i],ick[tot-i+1]);
	}
	for(int i=tot;i;i--)
	{
		int r=ick[i],ans1=0;
		while(1)
		{
			ans1++;
			int p=upper_bound(st+1,st+tot+1,r)-st;
			if(p>tot) break;
			else
			{
				if(!sum[p]) r=s[p].r;
				else
				{
					ans1+=sum[p];
					break;
				}
			}
		}
		sum[i]=ans1;
		ans=max(ans,ans1);
	}
	cout<<ans;
}
//4 3
//3 3 2 1

//4 2
//2 1 0 3

//4 3
//2 1 0 3

//4 0
//2 1 0 3

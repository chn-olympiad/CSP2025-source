#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
struct node
{
	int val,bel;
	int loc;
}a[100005];
bool vis[100005];
int t,n,len;
int ans;
bool cmp(node x,node y)
{
	if(x.val!=y.val)
		return x.val>y.val;
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club1.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		len=0;
		ans=0;
		int all_sum[5];
		memset(vis,0,sizeof vis);
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				all_sum[j]=0; 
				len++;
				cin>>a[len].val;
				a[len].loc=i;
				a[len].bel=j;
			}
		}
		sort(a+1,a+len+1,cmp);
		for(int i=1;i<=len;i++)
		{
			if(!vis[a[i].loc] && all_sum[a[i].bel]<n/2)
			{
				ans+=a[i].val;
				all_sum[a[i].bel]++;
				vis[a[i].loc]=1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

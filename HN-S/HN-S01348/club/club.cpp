#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
struct Node{
	int id,val;
};
struct stu{
	Node a[4];
}st[maxn];
int n,pos[maxn],k[maxn];
bool cmp(Node x,Node y)
{
	return x.val>y.val;
}
bool cmp1(stu x,stu y)
{
	if(x.a[1].val!=y.a[1].val)
		return x.a[1].val>y.a[1].val;
	return x.a[2].val<y.a[2].val;
 } 
bool cmp2(int x,int y)
{
	return (st[x].a[1].val-st[x].a[2].val)< (st[y].a[1].val-st[y].a[2].val);
}
void solve()
{
	int tot[4]={0};
	int ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>st[i].a[1].val>>st[i].a[2].val>>st[i].a[3].val;
		st[i].a[1].id=1;
		st[i].a[2].id=2;
		st[i].a[3].id=3;
		sort(st[i].a+1,st[i].a+3+1,cmp);
	}
	sort(st+1,st+n+1,cmp1);
	for(int i=1;i<=n;i++)
	{
	
			ans+=st[i].a[1].val;
			tot[st[i].a[1].id]++;
		pos[i]=st[i].a[1].id;
	}
	int cnt=0,t=-1;
	if(tot[1]>n/2)
	{
		t=tot[1]-n/2;
		for(int i=1;i<=n;i++)
		{
			if(pos[i]==1)
			{
				k[++cnt]=i;
			}
		}
	}
	if(tot[2]>n/2)
	{
		t=tot[2]-n/2;
		for(int i=1;i<=n;i++)
		{
			if(pos[i]==2)
			{
				k[++cnt]=i;
			}
		}
	}
	if(tot[3]>n/2)
	{
		t=tot[3]-n/2;
		for(int i=1;i<=n;i++)
		{
			if(pos[i]==3)
			{
				k[++cnt]=i;
			}
		}
	}
	if(t==-1)
	{
		cout<<ans<<"\n";
	}else
	{
		sort(k+1,k+cnt+1,cmp2);
		for(int i=1;i<=t;i++)
		{
			ans-=st[k[i]].a[1].val-st[k[i]].a[2].val;
		}
		cout<<ans<<"\n";
	}
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
}

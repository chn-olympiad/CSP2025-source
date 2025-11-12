#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<int,int>
vector<PII> bu;
ll a[5010];
struct{
	ll l,r;
	ll date;
}b[20001];
void build(ll note,ll l,ll r)
{
	if(l==r)
	{
		b[note].l=l;
		b[note].r=r;
		b[note].date=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(note*2,l,mid);
	build(note*2+1,mid+1,r);
	b[note].l=l;
	b[note].r=r;
	b[note].date=(b[note*2].date)xor(b[note*2+1].date);
	return;
}
ll treesum(ll note,ll l,ll r)
{
	if(l<=b[note].l&&b[note].r<=r)
	{
		return b[note].date;
	}
	ll ans1,ans2;
	bool i1=false,i2=false; 
	ll mid=(b[note].l+b[note].r)/2;
	if(mid>=l)
	{
		i1=true;
		ans1=(treesum(note*2,l,r));
	}
	if(mid+1<=r)
	{
		i2=true;
		ans2=(treesum(note*2+1,l,r));
	}
	if(i1&&!i2)
	{
		return ans1;
	}
	else if(i2&&!i1)
	{
		return ans2;
	}
	else if(i1&&i2)
	{
		return (ans1)xor(ans2);
	}
} 
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k;
	cin>>n>>k;
	bool zo=true;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1&&a[i]!=0)
		{
			zo=false;
		}
	}
	if(zo)
	{
		if(k==1)
		{
			int cnt=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==k)
				{
					cnt++;
				}
			}
			cout<<cnt;
			return 0;
		}
		else
		{
			int cnt=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1)
				{
					int u=0;
					for(int j=i;a[j]==1;j++)
					{
						u++;
					}
					cnt+=u/2;
				}
				else
				{
					int u=0;
					for(int j=i;a[j]==0;j++)
					{
						u++;
					}
					cnt+=u;
				}
			}
			cout<<cnt;
            return 0;
		}
	}
	build(1,1,n);
	for(ll i=1;i<=n;i++)
	{
		for(ll j=i;j<=n;j++)
		{
			if(treesum(1,i,j)==k)
			{
				bu.push_back(PII(i,j));	
			}
		}
	}
	int size=bu.size();
	bool use[size];
	memset(use,false,sizeof(use));
	int ans=0;
	for(int i=0;i<size;i++)
	{
		if(!use[i])
		{
			use[i]=true;
			int last=bu[i].second;
			int cnt=1;
			for(int j=i+1;j<size;j++)
			{
				if(bu[j].first>last)
				{
					cnt++;
					last=bu[j].second;
					use[j]=true;
				}
			}
			ans=max(ans,cnt);
		}
	}
	cout<<ans;
	return 0;
}


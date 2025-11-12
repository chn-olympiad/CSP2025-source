#include<bits/stdc++.h>
using namespace std;
#define int long long
int f[2000000],a[5000000];
struct node{
	int f,s;
}q[5000000];
int cnt;
void solve(int x,int k,int i)
{
	int s=1,num=0;
	while(x!=0||k!=0)
	{
		if(x%2!=k%2)
		{
			num+=s;
		}
		x/=2;
		k/=2;
		s*=2;
	}
	if(f[num]!=0)
	{
		q[++cnt].f=f[num]+1;
		q[cnt].s=i;
	}
	else if(num==0)
	{
		q[++cnt].f=1;
		q[cnt].s=i;
	}
}
bool cmp(node x,node y)
{
	return x.s<y.s;
}
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int s=0;
	for(int i=1;i<=n;i++)
	{
		s^=a[i];
		if(a[i]==k)
		{
			q[++cnt].f=i;
			q[cnt].s=i;
		}
		else solve(s,k,i);
		f[s]=i;
	}
	sort(q+1,q+cnt+1,cmp);
	int last=0,ans=0;
	for(int i=1;i<=cnt;i++)
	{
		if(last<q[i].f)
		{
			ans++;
			last=q[i].s;
		}
	}
	cout<<ans;
}

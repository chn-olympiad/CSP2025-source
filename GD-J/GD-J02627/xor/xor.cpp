#include<bits/stdc++.h>
using namespace std;
const int N=4000001;
int a[N],mx[N],n,m,sum,ans,f[N],tr[N],vis[N];
struct id{
	int l,r;
};
vector<id>pd;
int lowbit(int x)
{
	return x&(-x);
}
void add(int x,int y)
{
	while(x<N)
	{
		tr[x]=max(tr[x],y);
		x+=lowbit(x);
	}
}
int ask(int x)
{
	int ans=0;
	while(x>0)
	{
		ans=max(ans,tr[x]);
		x-=lowbit(x);
	}
	return ans;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	vis[0]=1;
	for(int i=1;i<=n;i++)
	{
		sum^=a[i];
		if(vis[sum^m])
		{
			pd.push_back({mx[sum^m]+1,i});
		}
		vis[sum]=1;
		mx[sum]=max(mx[sum],i);
	}
	int pdafx=pd.size();
	for(int i=0;i<pdafx;i++)
	{
		f[i]=ask(max(pd[i].l-1,0))+1;
		add(pd[i].r,f[i]);
	}
	for(int i=0;i<pdafx;i++)
	{
		ans=max(ans,f[i]);
	}
	cout<<ans;
}
 
 

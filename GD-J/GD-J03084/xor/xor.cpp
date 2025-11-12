#include<bits/stdc++.h>
using namespace std;
const int N=5e5+50;
int n,k,a[N],sum[N],p[1<<20],l[N],cnt=0,tree[N<<2],tag[N<<2],ans=0;
struct node
{
	int l,r,d;
}q[500500];
int ls(int x){return x<<1;}
int rs(int x){return x<<1|1;}
void updata(int p)
{
	tree[p]=max(tree[ls(p)],tree[rs(p)]);
	return;
}
void tag_down(int p)
{
	if(tag[p])
	{
		tree[ls(p)]+=tag[p];
		tree[rs(p)]+=tag[p];
		tag[ls(p)]+=tag[p];
		tag[rs(p)]+=tag[p];
		tag[p]=0;
	}
}
void change(int p,int pl,int pr,int l,int r,int d)
{
	if(l<=pl&&pr<=r)
	{
		tree[p]+=d;
		tag[p]+=d;
		return;
	}
	tag_down(p);
	int mid=(pl+pr)>>1;
	if(mid>=l)
	{
		change(ls(p),pl,mid,l,r,d);
	}
	if(mid<r)
	{
		change(rs(p),mid+1,pr,l,r,d);
	}
	updata(p);
}
int mmax(int p,int pl,int pr,int l,int r)
{
	if(l<=pl&&pr<=r)
	{
		return tree[p];
	}
	tag_down(p);
	updata(p);
	int mid=(pl+pr)>>1,res=-1;
	if(mid>=l)
	{
		res=max(res,mmax(ls(p),pl,mid,l,r));
	}
	if(mid<r)
	{
		res=max(res,mmax(rs(p),mid+1,pr,l,r));
	}
	return res;
}
bool cmp(node x,node y)
{
	if(x.d==y.d)
		return x.l<y.l;
	return x.d<y.d;
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
		p[k^sum[i-1]]=i;
		if(p[sum[i]]!=0&&l[p[sum[i]]]==0)
		{
			cnt++;
			q[cnt].l=p[sum[i]];
			q[cnt].r=i;
			q[cnt].d=q[cnt].r-q[cnt].l+1;
			l[p[sum[i]]]=i;
		}
	}
	sort(q+1,q+1+cnt,cmp);
	for(int i=1;i<=cnt;i++)
	{
		if(mmax(1,1,n,q[i].l,q[i].r)<1)
		{
			change(1,1,n,q[i].l,q[i].r,1);
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
/*
4 3
2 1 0 3

4 0
2 1 0 3
*/

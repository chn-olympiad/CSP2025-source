#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,k,ans,last,cnt,a[500001];
bool ts1=true,ts2=true;

struct node
{
	int l;
	int r;
	int value;
}z[2000001];

struct line
{
	int l;
	int r;
}b[2000001];

void build(int now,int l,int r)
{
	z[now].l=l;
	z[now].r=r;
	if(l==r)
	{
		z[now].value=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(now*2,l,mid);
	build(now*2+1,mid+1,r);
	z[now].value=z[now*2].value^z[now*2+1].value;
	return;
}

int g(int now,int l,int r)
{
	if(z[now].l>=l&&z[now].r<=r)
	{
		return z[now].value;
	}
	int mid=(z[now].l+z[now].r)>>1,sum=0;
	if(mid>=l) sum^=g(now*2,l,r);
	if(mid+1<=r) sum^=g(now*2+1,l,r);
	return sum;
}

bool cmp(line q,line p)
{
	if(q.r!=p.r) return q.r<p.r;
	return q.l<p.l;
}

signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		if(a[i]!=1) ts1=false;
		if(a[i]!=0&&a[i]!=1) ts2=false;
	}
	if(ts1)
	{
		cout<<n/2;
		return 0;
	}
	if(ts2)
	{
		for(int i=1;i<=n;++i)
		{
			if(a[i]==1) ++cnt;
			a[i]=cnt;
		}
		if(k==1)
		{
			cout<<cnt;
			return 0;
		}
		int last=0,s=0;
		for(int i=1;i<=n;++i)
		{
			if(!a[i])
			{
				++ans;
				if(s)
				{
					ans+=s/2;
					s=0;
				}
				continue;
			}
			++s;
		}
		cout<<ans;
	}
	build(1,1,n);
	for(int i=1;i<=n;++i)
	{
		for(int j=i;j<=n;++j)
		{
			if(g(1,i,j)==k)
			{
				b[++cnt].l=i;
				b[cnt].r=j;
			}
		}
	}
	sort(b+1,b+cnt+1,cmp);
	for(int i=1;i<=cnt;++i)
	{
		while(1)
		{
			if(i>cnt) break;
			if(b[i].l<=last)
			{
				++i;
				continue;
			}
			last=b[i].r;
			++ans;
			++i;
		}
	}
	cout<<ans;
	return 0;
}

/*
不要爆我准考证号，谢谢！！！

书接上回 
我靠T3是什么东西我就不说了，O(n^2*logn)的时间复杂度还不一定正确，有救吗wc
期望得到30~65分啊wc
言归正传 
崩3其实挺好玩的，奖励也多，福利也好，角色也很好养，但是还是没时间，所以角色比较少。
常驻一大堆的0+0，但也有1个0+1，是空之律者
然后孩子是去年11月入坑的，所以up很少，如下：
0+0：薇塔，这个版本的爱莉希雅
0+1：2025年过年那个版本的琪亚娜（炽愿吉星）
1+1：2025年暑假那个版本的科拉莉 
*/







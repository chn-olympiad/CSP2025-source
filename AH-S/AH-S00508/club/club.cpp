#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005];
struct node{
	int number,sz;
}bh[100005];
int t,n;				//t组数据，n个人
int a1,b1,c1;			//选择n社团的有n1个人
int ans,maxn,minn;
int cmp(node x,node y)
{
	return x.sz>y.sz;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int l=1;l<=t;l++)
	{
		a1=0;b1=0;c1=0;ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			maxn=0;minn=0;
			cin>>a[i]>>b[i]>>c[i];
			maxn=max(a[i],b[i]);
			maxn=max(c[i],maxn);
			minn=min(a[i],b[i]);
			minn=min(c[i],minn);
			int zj=0;
			zj=a[i]+b[i]+c[i]-maxn-minn;
			//求最大与第二大的数值并求出变化量
			bh[i].sz=maxn-zj;
			bh[i].number=i;
		}
		sort(bh+1,bh+1+n,cmp);	//排序求最大变化值
		/*
		 * 加上数值变化值最大的数的最大值
		 * 如果有社团满了，就得换掉
		 */
		 maxn=0;minn=0;
		for(int i=1;i<=n;i++)
		{
			int num=bh[i].number;
			maxn=max(a[num],b[num]);
			maxn=max(c[num],maxn);
			minn=min(a[num],b[num]);
			minn=min(c[num],minn);
			int zj=0;
			zj=a[num]+b[num]+c[num]-maxn-minn;
			if(a[num]==maxn)
			{
				a1++;
				if(a1>n/2)
					ans+=zj;
				else
					ans+=maxn;
				continue;
			}
			if(b[num]==maxn)
			{
				b1++;
				if(b1>n/2)
					ans+=zj;
				else
					ans+=maxn;
				continue;
			}
			if(c[num]==maxn)
			{
				c1++;
				if(c1>n/2)
					ans+=zj;
				else
					ans+=maxn;
				continue;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
struct s
{
	int a1;
	int a2;
	int a3;
	int bh;
}a[100010],b[100010],c[100010];
int work()
{
	int n,top1=1,top2=1,top3=1,rsa=0,rsb=0,rsc=0,ans=0,maxn,C;
	cin>>n;
	bool yue[n+1]={0};
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].a1>>a[i].a2>>a[i].a3;
		a[i].bh=i;
		b[i]=a[i];
		c[i]=a[i];
	}
	for(int i=n;i>0;i--)
	  for(int j=1;j<i;j++)
		if((a[j].a1<a[j+1].a1) || (a[j].a1==a[j+1].a1 && a[j].a2<a[j+1].a2) || (a[j].a1==a[j+1].a1 && a[j].a2==a[j+1].a2 && a[j].a3<a[j+1].a3))swap(a[j],a[j+1]);
	for(int i=n;i>0;i--)
	  for(int j=1;j<i;j++)
		if((b[j].a2<b[j+1].a2) || (b[j].a2==b[j+1].a2 && b[j].a1<b[j+1].a1) || (b[j].a1==b[j+1].a1 && b[j].a2==b[j+1].a2 && b[j].a3<b[j+1].a3))swap(b[j],b[j+1]);
	for(int i=n;i>0;i--)
	  for(int j=1;j<i;j++)
		if((c[j].a3<c[j+1].a3) || (c[j].a3==c[j+1].a3 && c[j].a1<c[j+1].a1) || (c[j].a1==c[j+1].a1 && c[j].a3==c[j+1].a3 && c[j].a2<c[j+1].a2))swap(c[j],c[j+1]);
	while(top1<=n || top2<=n || top3<=n)
	{
		if(top1<=n && rsa<n/2 && yue[a[top1].bh]==0)
		{
			C=1;
			maxn=a[top1].a1;
			if(top2<=n && a[top1].bh==b[top2].bh && maxn<b[top2].a2 && rsb<n/2){C=2;maxn=b[top2].a2;}
			if(top3<=n && a[top1].bh==c[top3].bh && maxn<c[top3].a3 && rsc<n/2){C=3;maxn=c[top3].a3;}
			ans+=maxn;
			switch(C)
			{
				case 1:rsa++;yue[a[top1].bh]=1;break;
				case 2:rsb++;yue[b[top2].bh]=1;break;
				case 3:rsc++;yue[c[top3].bh]=1;break;
			}
			if(a[top1].bh==c[top3].bh)top3++;
			if(a[top1].bh==b[top2].bh)top2++;
			top1++;
			continue;
		}
		top1++;
		if(top2<=n && rsb<n/2 && yue[b[top2].bh]==0)
		{
			C=2;
			maxn=b[top2].a2;
			if(top1<=n && a[top1].bh==b[top2].bh && maxn<a[top1].a1 && rsa<n/2){C=1;maxn=a[top1].a1;}
			if(top2<=n && b[top2].bh==c[top3].bh && maxn<c[top3].a3 && rsc<n/2){C=3;maxn=c[top3].a3;}
			ans+=maxn;
			switch(C)
			{
				case 1:rsa++;yue[a[top1].bh]=1;break;
				case 2:rsb++;yue[b[top2].bh]=1;break;
				case 3:rsc++;yue[c[top3].bh]=1;break;
			}
			if(b[top2].bh==c[top3].bh)top3++;
			if(a[top1].bh==b[top2].bh)top1++;
			top2++;
			continue;
		}
		top2++;
		if(top3<=n && rsc<n/2 && yue[c[top3].bh]==0)
		{
			C=3;
			maxn=c[top3].a3;
			if(top1<=n && c[top3].bh==a[top1].bh && maxn<a[top1].a1 && rsa<n/2){C=1;maxn=a[top1].a1;}
			if(top2<=n && b[top2].bh==c[top3].bh && maxn<b[top2].a2 && rsb<n/2){C=2;maxn=b[top2].a2;}
			ans+=maxn;
			switch(C)
			{
				case 1:rsa++;yue[a[top1].bh]=1;break;
				case 2:rsb++;yue[b[top2].bh]=1;break;
				case 3:rsc++;yue[c[top3].bh]=1;break;
			}
			if(b[top2].bh==c[top3].bh)top2++;
			if(a[top1].bh==c[top3].bh)top1++;
			top3++;
			continue;
		}
		top3++;
	}
	return ans;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int sum[t+1];
	for(int i=1;i<=t;i++)
	  sum[i]=work();
	for(int i=1;i<=t;i++)
	  cout<<sum[i]<<endl;
	return 0;
}
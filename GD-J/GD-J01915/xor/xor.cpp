#include<bits/stdc++.h>
using namespace std;
map<int,int> my_map;
int n,m,k=1,kk,sum,ans,ff,a[500005],b[10005][10005];
struct node
{
	int l=0,r;
}q[500005];
struct fas
{
	int l,r;
}q1[500005];
int cmp(fas a,fas b)
{
	if(a.r!=b.r) return a.r<b.r;
	return a.l<b.l;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>1) ff=1;
		if(a[i]==m) q[k].l=q[k-1].r+1,q[k].r=i,k++;
	}
	if(ff==0&&m==1)
	{
		for(int i=1;i<=n;i++) if(a[i]==1) ans++;
		cout<<ans,exit(0); 
	}
	if(ff==0&&m==0)
	{
		for(int i=1;i<=n;i++) if(a[i]==0) ans++;
		for(int i=1;i<=n;i++) if(a[i]==1&&a[i+1]==1) ans++,i++;
		cout<<ans,exit(0);
	}
	if(a[n]==m) k--;
	else q[k].l=q[k-1].r+1,q[k].r=n;
	for(int i=1;i<=k;i++)
	{
		int sum=0,maxx=0,kk=0,ll=0;
		for(int l=q[i].l;l<=q[i].r;l++)
		{
			sum=0;
			int tt=l;
			for(int l1=l;l1<=q[i].r;l1++)
			{
				sum^=a[l1];
				if(sum==m) kk++,sum=0,b[tt][l1]++,q1[kk].l=tt,q1[kk].r=l1,tt=l1+1;
			}
		}
		sort(q1+1,q1+kk+1,cmp);
		for(int j=1;j<=kk;j++)
		{
			if(q1[j].l>ll) ans++,ll=q1[j].r;
		}
	}
	cout<<ans;
}
//是个可敬的对手 

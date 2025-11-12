#include<bits/stdc++.h>
using namespace std;
struct wsy{int num,z;};
bool wxhn(wsy a,wsy b)
{
	if(a.z!=b.z)return a.z<b.z;
	return a.num<b.num;
}

struct xd{int l,r;};
bool cmp(xd a,xd b)
{
	return a.r<b.r;
}

int sum[500005];
wsy sy[500005];
xd tx[500005];//线段覆盖 
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k;cin>>n>>k;//输入与前缀和 
	for(int i=1;i<=n;i++)
	{
		int a;cin>>a;
		
		sum[i]=a^sum[i-1];
		
		sy[i].z=sum[i];
		sy[i].num=i;
	}
	
	//寻找最近的值为k的端点 构造线段 
	sort(sy+1,sy+1+n,wxhn);//sy与sum相同，但具有单调性可以二分 
	for(int i=1;i<=n;i++)
	{
		tx[i].l=i;tx[i].r=INT_MAX;
		int si=sum[i-1];
		int sj=k^si;//要找的答案 
		int s=1,e=n;
		while(s<e)
		{
			int mid=(s+e)/2;
			if(sy[mid].z<sj)s=mid+1;
			else if(sj<sy[mid].z)e=mid-1;
			else
			{
				if(sy[mid].num<i)s=mid+1;
				else e=mid;
			}
		}
		if(sy[e].z==sj&&sy[e].num>=i)tx[i].r=sy[e].num;
	}
	
	//线段覆盖 
	sort(tx+1,tx+1+n,cmp);
	int ans=0,rn=0;
	for(int i=1;i<=n;i++)
	{
		if(tx[i].l>rn&&tx[i].r<=n)
		{
			ans++;
			rn=tx[i].r;
		}
	}
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,z,ok,min1[100005];
int cha_1_2[100005],cha_1_3[100005],cha_2_3[100005];
int cha_2_1[100005],cha_3_1[100005],cha_3_2[100005];
struct node{
	int q,w,e;
}a[100005];
bool cmp(node x,node y)
{
	if(x.q!=y.q)  return x.q>y.q;
	return x.w>y.w;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--)
	{
		int sum=0,sum1=0,sum2=0,cnt=0,cnt1=0,cnt2=0;
		scanf("%lld",&z);
		for(int i=1;i<=z;i++)
		{
			scanf("%lld%lld%lld",&a[i].q,&a[i].w,&a[i].e);
			cha_1_2[i]=a[i].q-a[i].w;
			cha_1_3[i]=a[i].q-a[i].e;
			cha_2_3[i]=a[i].w-a[i].e;
			
			cha_2_1[i]=a[i].w-a[i].q;
			cha_3_1[i]=a[i].e-a[i].q;
			cha_3_2[i]=a[i].e-a[i].w;
			int max1=max(max(a[i].q,a[i].w),a[i].e);
			if(max1==a[i].q)  sum+=a[i].q,cnt++;
			else if(max1==a[i].w)  sum1+=a[i].w,cnt1++;
			else if(max1==a[i].e)  sum2+=a[i].e,cnt2++;
			if(a[i].w!=0||a[i].e!=0)  ok=1;
		}
		if(ok==0)
		{
			sort(a+1,a+z+1,cmp);
			int ans=0;
			for(int i=1;i<=z/2;i++)  ans+=a[i].q;
			printf("%lld\n",ans);
		}
		else if(cnt<=z/2&&cnt1<=z/2&&cnt2<=z/2)  printf("%lld\n",sum+sum1+sum2);
		else
		{
			if(cnt>z/2)
			{
				memset(min1,LLONG_MIN,sizeof min1);
				int p=cnt-z/2,q=0;
				for(int i=1;i<=z;i++)
				{
					if(max(max(a[i].q,a[i].w),a[i].e)==a[i].q)  min1[i]=min(cha_1_3[i],cha_1_2[i]);
					else  q++;
				}
				sort(min1+1,min1+z+1);
				for(int i=q+1;i<=q+p;i++)  sum-=min1[i];
				printf("%lld\n",sum+sum1+sum2);
			}
			else if(cnt1>z/2)
			{
				memset(min1,LLONG_MIN,sizeof min1);
				int p=cnt1-z/2,q=0;
				for(int i=q+1;i<=q+z;i++)
				{
					if(max(max(a[i].q,a[i].w),a[i].e)==a[i].w)  min1[i]=min(cha_2_1[i],cha_2_3[i]);
					else  q++;
				}
				sort(min1+1,min1+z+1);
				for(int i=q;i<=q+p;i++)  sum1-=min1[i];
				printf("%lld\n",sum+sum1+sum2);
			}
			else if(cnt2>z/2)
			{
				memset(min1,LLONG_MIN,sizeof min1);
				int p=cnt2-z/2,q=0;
				for(int i=1;i<=z;i++)
				{
					if(max(max(a[i].q,a[i].w),a[i].e)==a[i].e)  min1[i]=min(cha_3_1[i],cha_3_2[i]);
					else  q++;
				}
				sort(min1+1,min1+z+1);
				for(int i=q+1;i<=q+p;i++)  sum2-=min1[i];
				printf("%lld\n",sum+sum1+sum2);
			}
		}
	}
	return 0;
}

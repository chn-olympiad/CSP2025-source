#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N][4];
struct u
{
	int cha,id;
}b[N];
bool cmp(u x,u y)
{
	return x.cha<y.cha;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		int ans=0;
		int cnt[4];
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++)
		{
			int ind=0,num=0,sec=0;
			for(int k=1;k<=3;k++)
				if(a[i][k]>num)sec=num,num=a[i][k],ind=k;
				else if(sec<a[i][k])sec=a[i][k];
			ans+=num;
			cnt[ind]++;
			b[i].id=ind;
			b[i].cha=num-sec;
		}
		sort(b+1,b+n+1,cmp);
		for(int k=1;k<=3;k++)
		{
			if(cnt[k]<=n/2)continue;
			for(int i=1;i<=n;i++)
			{
				if(b[i].id!=k)continue;
				ans-=b[i].cha;
				cnt[k]--;
				if(cnt[k]==n/2)break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

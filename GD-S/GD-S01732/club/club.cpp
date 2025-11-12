#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=1e5+100;
int t,n,b[5][N],bk[5],mk;
ll ans;
struct nodema
{
	int num,id;	
}ma[5];
struct node
{
	int a1,a2,a3,ma1,ma2,ma3,mk1,mk2,mk3,c;
}a[N];
bool cmp(nodema b1,nodema b2)
{
	return b1.num>b2.num;
}
bool cmp2(int b1,int b2)
{
	return a[b1].c<a[b2].c;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		bk[1]=bk[2]=bk[3]=ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) 
		{
			scanf("%d%d%d",&a[i].a1,&a[i].a2,&a[i].a3);
			ma[1].num=a[i].a1,ma[2].num=a[i].a2,ma[3].num=a[i].a3;
			ma[1].id=1,ma[2].id=2,ma[3].id=3;
			sort(ma+1,ma+3+1,cmp);
			a[i].ma1=ma[1].num,a[i].ma2=ma[2].num,a[i].ma3=ma[3].num;
			a[i].mk1=ma[1].id,a[i].mk2=ma[2].id,a[i].mk3=ma[3].id;
			a[i].c=a[i].ma1-a[i].ma2;
			b[a[i].mk1][++bk[a[i].mk1]]=i;
			if(bk[a[i].mk1]>=bk[a[i].mk2]&&bk[a[i].mk1]>=bk[a[i].mk3]) mk=a[i].mk1;
			ans+=a[i].ma1;
		}
		if(bk[mk]>n/2)
		{
			sort(b[mk]+1,b[mk]+bk[mk]+1,cmp2);
			for(int i=1;i<=bk[mk]-n/2;i++) ans-=a[b[mk][i]].c;
		}
		printf("%lld\n",ans);
	}
	return 0;
} 

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<fstream>
using namespace std;
int t,n,m,k,x,w_ans,w_num[5],a[100005][5],b[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		k=0;
		w_ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<4;j++)
				scanf("%d",&a[i][j]);
			x=max(a[i][1],max(a[i][2],a[i][3]));
			w_ans+=x;
			if(a[i][1]==x)
				w_num[1]++;
			else if(a[i][2]==x)
				w_num[2]++;
			else
				w_num[3]++;
		}
//		printf("num[1]=%d,num[2]=%d,num[3]=%d\n",w_num[1],w_num[2],w_num[3]);
		if(max(w_num[1],max(w_num[2],w_num[3]))>n/2)
		{
			if(w_num[1]>n/2)
				m=1;
			else if(w_num[2]>n/2)
				m=2;
			else
				m=3;
//			printf("m=%d\n",m);
			for(int i=1;i<=n;i++)
			{
				x=max(a[i][1],max(a[i][2],a[i][3]));
				if(a[i][1]==x&&m==1)
					b[++k]=x-max(a[i][2],a[i][3]);
				else if(a[i][2]==x&&m==2)
					b[++k]=x-max(a[i][1],a[i][3]);
				else if(m==3&&a[i][3]==x)
					b[++k]=x-max(a[i][1],a[i][2]);
			}
			sort(b+1,b+1+k);
//			printf("b[]:");
//			for(int i=1;i<=k;i++)
//				printf("%d ",b[i]);
//			printf("\nx=%d\n",x);
			x=max(w_num[1],max(w_num[2],w_num[3]))-n/2;
			for(int i=1;i<=x;i++)
				w_ans-=b[i];
		}
		printf("%d\n",w_ans);
		for(int i=0;i<4;i++)
			w_num[i]=0;
	}
	return 0;
}

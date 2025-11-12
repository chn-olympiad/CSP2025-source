//GZ-S00211 贵州省铜仁第一中学 李佶鸿
#include <bits/stdc++.h>
using namespace std;

struct mem{
	int a[4],maxa[4],sel;
}m[100010];
bool cmp(mem a1,mem a2)
{
	if(a1.a[a1.maxa[0]]!=a2.a[a2.maxa[0]])return a1.a[a1.maxa[0]]>a2.a[a2.maxa[0]];
	if(a1.a[a1.maxa[1]]!=a2.a[a2.maxa[1]])return a1.a[a1.maxa[1]]>a2.a[a2.maxa[1]];
	return a1.a[a1.maxa[2]]>a2.a[a2.maxa[2]];
}
int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--)
	{
		memset(m,0,sizeof m);
		int n,bm[4]={0},bs[4]={0};
		memset(bm,0,sizeof bm);
		memset(bs,0,sizeof bs);
		cin >> n;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&m[i].a[0],&m[i].a[1],&m[i].a[2]);
			if(m[i].a[0]>=m[i].a[1] && m[i].a[1]>=m[i].a[2])m[i].sel=0,m[i].maxa[0]=0,m[i].maxa[1]=1,m[i].maxa[2]=2;//{1,2,3}
			if(m[i].a[1]<=m[i].a[2] && m[i].a[0]>=m[i].a[2])m[i].sel=0,m[i].maxa[0]=0,m[i].maxa[1]=2,m[i].maxa[2]=1;//{1,3,2}
			if(m[i].a[0]>=m[i].a[1] && m[i].a[0]<=m[i].a[2])m[i].sel=2,m[i].maxa[0]=2,m[i].maxa[1]=0,m[i].maxa[2]=1;//{3,1,2};
			if(m[i].a[0]<=m[i].a[1] && m[i].a[1]<=m[i].a[2])m[i].sel=2,m[i].maxa[0]=2,m[i].maxa[1]=1,m[i].maxa[2]=0;//{3,2,1};
			if(m[i].a[0]<=m[i].a[1] && m[i].a[0]>=m[i].a[2])m[i].sel=1,m[i].maxa[0]=1,m[i].maxa[1]=0,m[i].maxa[2]=2;//{2,1,3};
			if(m[i].a[1]>=m[i].a[2] && m[i].a[0]<=m[i].a[2])m[i].sel=1,m[i].maxa[0]=1,m[i].maxa[1]=2,m[i].maxa[2]=0;//{2,3,1};
		}
		sort(m+1,m+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<3;j++)
			{
				bool flag=false;
				if(bm[m[i].maxa[j]]+1<=n/2)
				{
					bm[m[i].maxa[j]]++;
					bs[m[i].maxa[j]]+=m[i].a[m[i].maxa[j]];
					m[i].sel=m[i].maxa[j];
					break;
				}else
				{
					for(int k=1;k<=bm[0]+bm[1]+bm[2];k++)
					{
						
						for(int l=1;l<=2;l++)
						{
							
							if(m[k].a[m[k].sel]-m[k].a[(m[k].sel+l)%3]<m[i].a[m[k].sel])
							{
								flag=true;
								m[i].sel=m[k].sel;
								bs[m[k].sel]-=m[k].a[m[k].sel];
								bm[m[k].sel]--;
								bs[m[i].sel]+=m[i].a[m[i].sel];
								bm[m[i].sel]++;
								if(bm[(m[k].sel+l)%3]+1<=n/2)
								{
									bm[(m[k].sel+l)%3]++;
									bs[(m[k].sel+l)%3]+=m[k].a[(m[k].sel+l)%3];
									m[k].sel=(m[k].sel+l)%3;
								}
								
								mem tmp;
								tmp=m[k];
								m[k]=m[i];
								m[i]=m[k];	
								break;
							}
							
						}
						if(flag)break;
					}
				}
				if(flag)break;
			}
		}
		cout << bs[0]+bs[1]+bs[2] << endl;
	}
	return 0;
}

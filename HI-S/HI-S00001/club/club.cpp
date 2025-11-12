#include <bits/stdc++.h>
using namespace std;
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
int T,n;
struct st
{
	long long s1,s2,s3;
};
struct st2
{
	int id,num,ans;
};
st a[100005];
vector <st2> f[4];
bool cmp1(st x,st y)
{
	return max(x.s1,x.s2)>max(y.s1,y.s2);
}
bool cmp(st x,st y)
{
	return max(x.s1,x.s2)==max(y.s1,y.s2)? abs(x.s1-x.s2)>abs(y.s1-y.s2):  max(x.s1,x.s2)==max(y.s1,y.s2)  ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T)
	{
		T--;
		scanf("%d",&n);
		int b=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&a[i].s1,&a[i].s2,&a[i].s3);
			if(a[i].s2==0)
			{
				b++;
			}
		}
		if(b==n)
		{
			sort(a+1,a+1+n,cmp1);
			long long sum=0;
			for(int i=1;i<=n/2;i++)
			{
				sum+=a[i].s1;
			 } 
			printf("%lld\n",sum);
		}else
		{
			sort(a+1,a+1+n,cmp);
			long long sum=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i].s1>a[i].s2)
				{
					if(f[1].size()<n/2)
					{
						f[1].push_back({i,a[i].s1,a[i].s1-a[i].s2});
					}else
					{
						for(int j=0;j<f[1].size();j++)
						{
							if(f[1][j].ans<a[i].s1)
							{
								f[2].push_back({f[1][j].id,f[1][j].num,f[1][j].ans});
								f[1][j].id=i;
								f[1][j].num=a[i].s1;
								f[1][j].ans=a[i].s1-a[i].s2;
							}
						}
					}
				}else
				{
					if(f[2].size()<n/2)
					{
						f[2].push_back({i,a[i].s2,a[i].s2-a[i].s1});
					}else
					{
						for(int j=0;j<f[2].size();j++)
						{
							if(f[2][j].ans<a[i].s2)
							{
								f[1].push_back({f[2][j].id,f[2][j].num,f[2][j].ans});
								f[2][j].id=i;
								f[2][j].num=a[i].s2;
								f[2][j].ans=a[i].s2-a[i].s1;
							}
						}
					}
				}
			}
			for(int i=0;i<f[1].size();i++)
			{
				sum+=f[1][i].num;
			}
			for(int i=1;i<f[2].size();i++)
			{
				sum+=f[2][i].num;
			}
			printf("%lld\n",sum);
		}
	}
	return 0;
}


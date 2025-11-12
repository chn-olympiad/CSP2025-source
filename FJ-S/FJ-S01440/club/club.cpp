#include<bits/stdc++.h>
using namespace std;
#define forr(a,x,y) for(int a=x; a<=y; a++)
const int N=5e5+5;
int t,n;
long long res=0;
int a[N][5];
int tmp[N];
bool cmp(int a,int b){return a>b;}
void solve2()
{
	for(int i=1; i<=3; i++)
	{
		for(int j=1; j<=3; j++)
		{
			if(!(i==1 && j==1)) res=max(res,(long long)(a[1][i]+a[2][j]));
		}
	}
}
void solve4()
{
	forr(q,1,3)
	{
		forr(w,1,3)
		{
			forr(e,1,3)
			{
				forr(r,1,3)
				{
					int cnt[4]={0,0,0,0};
					cnt[q]++,cnt[w]++,cnt[e]++,cnt[r]++;				
					if(cnt[1]<=n/2 && cnt[2]<=n/2 && cnt[3]<=n/2) res=max(res,(long long)(a[1][q]+a[2][w]+a[3][e]+a[4][r]));
				}
			}
		}
	}
}
void solve10()
{
	forr(q,1,3)
	{
		forr(w,1,3)
		{
			forr(e,1,3)
			{
				forr(r,1,3)
				{
					forr(t,1,3)
					{
						forr(y,1,3)
						{
							forr(u,1,3)
							{
								forr(i,1,3)
								{
									forr(o,1,3)
									{
										forr(p,1,3)
										{
											int cnt[4]={0,0,0,0};
											cnt[q]++,cnt[w]++,cnt[e]++,cnt[r]++,cnt[t]++,cnt[y]++,cnt[u]++,cnt[i]++,cnt[o]++,cnt[p]++;
											if(cnt[1]<=n/2 && cnt[2]<=n/2 && cnt[3]<=n/2) res=max(res,(long long)(a[1][q]+a[2][w]+a[3][e]+a[4][r]+a[5][t]+a[6][y]+a[7][u]+a[8][i]+a[9][o]+a[10][p]));
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int I=1; I<=t; I++)
	{
		res=0;
		scanf("%d",&n);
		bool isAll0=true;
		for(int i=1; i<=n; i++)
		{
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			isAll0=(a[i][2]!=0 || a[i][3]!=0? false:isAll0);
			tmp[i]=a[i][1];
		}
		if(n==2) solve2();
		else if(n==4) solve4();
		else if(n==10) solve10();
		else if(isAll0==true)
		{
			sort(tmp+1,tmp+n+1,cmp);
			for(int i=1; i<=n/2; i++) res+=tmp[i];
		}
		printf("%lld\n",res);
	}
	return 0;
}

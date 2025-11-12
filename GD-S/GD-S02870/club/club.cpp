#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n;
struct aa{
	int v,w; 
};
struct cun{
	aa zz[5];
}ans[100005];
bool cmp(aa a,aa b)
{
	return a.v>b.v;
}
int zu[6];
int kk[6][100003];
int sum;
void init()
{
	memset(ans,0,sizeof(ans));
	memset(zu,0,sizeof(zu));
	memset(kk,0,sizeof(kk));
	sum=0;
}
void aaa()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<3;j++)
		{
			cin>>ans[i].zz[j].v;
			ans[i].zz[j].w=j+1;
		}
		sort(ans[i].zz+0,ans[i].zz+3,cmp);
	}
	for(int i=1;i<=n;i++)
	{
		int x=ans[i].zz[0].w;
		if(zu[x]>=n/2)
		{
			int y=ans[i].zz[1].w; 
			int maxx=1,cccc=1;
			for(int j=2;j<=zu[x];j++)
			{
				int k=kk[x][j];
				if(ans[k].zz[1].v-ans[k].zz[0].v>ans[maxx].zz[1].v-ans[maxx].zz[0].v)
				{
					maxx=k,cccc=j;
				}
			}
			if(ans[i].zz[1].v-ans[i].zz[0].v<ans[maxx].zz[1].v-ans[maxx].zz[0].v)
			{
				kk[x][cccc]=i;
				sum-=ans[maxx].zz[0].v;
				int yy=ans[maxx].zz[1].w;
				zu[yy]++;
				kk[yy][zu[yy]]=maxx;
				sum+=ans[maxx].zz[1].v;
				maxx=i;
				sum+=ans[i].zz[0].v;
			}
			else
			{
				zu[y]++;
				kk[y][zu[y]]=i;
				sum+=ans[i].zz[1].v;
			}	
		}
		else
		{
			zu[x]++;
			kk[x][zu[x]]=i;
			sum+=ans[i].zz[0].v;
		}
	}
	cout<<sum<<endl;
	return;
}
int T;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		init();
		aaa();
	}
	return 0;
}

#include<iostream>
#include<cstdio>
#include<queue>
#include<utility>
#include<cmath>
#include<fstream>
using namespace std;
int n,k,x,w_ans,a[500005],f[500005],b[500005];
queue<pair<int,int> > q;
pair<int,int> y;
bool w_check()
{
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=1||a[i]!=0)
			return 0;
	}
	return 1;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(w_check())
	{
		if(!k)
		{
			for(int i=1;i<=n;i++)
			{
				if(!a[i])
					w_ans++;
				else if(a[i+1])
				{
					w_ans++;
					i++;
				}
			}
		}
		if(k==1)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i])
					w_ans++;
			}
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			x=0;
			for(int j=i;j<=n;j++)
			{
				x^=a[j];
				if(x==k)
				{
					f[i]=j;
					break;
				}
			}
		}
		q.push({0,0});
		while(!q.empty())
		{
			y=q.front();
			q.pop();
			if(y.second<b[y.first])
				continue;
			for(int i=y.first+1;i<=n;i++)
			{
				if(f[i])
				{
					if(b[y.first]+1>b[f[i]])
					{
						b[f[i]]=b[y.first]+1;
						q.push({f[i],b[y.first]+1});
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
			w_ans=max(w_ans,b[i]);
	}
	printf("%d",w_ans);
	return 0;
} 

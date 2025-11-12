#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,ans,t[5],r[N][5],z,d[N]; 
struct stu
{
	int v,w;
	bool operator<(const stu& x)const
	{
		return x.w>this->w;
	}
};
priority_queue<stu>a[N];
vector<stu>c[N];
int in()
{
	int w=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		w=w*10+c-'0';
		c=getchar(); 
	}
	return f*w;
}
void dfs(int k,int s)
{
	if(k==n+1)
	{
		ans=max(ans,s);
		return;
	}
	for(stu j:c[k])
	{
		if(t[j.v]>=n/2) continue;
		t[j.v]++;
		dfs(k+1,s+j.w);
		t[j.v]--;
	}
}
bool check()
{
	for(int i=1;i<=n;i++)
	{
		d[i]=r[i][1];
		for(int j=2;j<=3;j++)
			if(r[i][j]!=0) return false;
	}
	return true;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		ans=0;
		n=in();
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
			{
				z=in();
				a[i].push({j,z});
				r[i][j]=z;
			}
		if(check())
		{
			sort(d+1,d+n+1);
			for(int i=n;i>=n/2;i--) ans+=d[i];
			printf("%d\n",ans);
			continue;
		}
		for(int i=1;i<=n;i++)
			while(a[i].size())
			{
				c[i].push_back(a[i].top());
				a[i].pop();
			}
		dfs(1,0);
		printf("%d\n",ans);
		for(int i=1;i<=n;i++) 
			while(c[i].size()) c[i].pop_back();
	}
	return 0;
 } 
/*

4 2 1
3 2 4
5 3 4
3 5 1


0 1 0
0 1 0
0 2 0
0 2 0


10 9 8
 4 0 0

*/

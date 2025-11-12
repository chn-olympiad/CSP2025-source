#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,a[N][5],best[N],secd[N],t[5];
priority_queue<int,vector<int>,greater<int>> q;
int solve(int res,int k)
{
	while(q.size())q.pop();
	for(int i=1;i<=n;i++)
		if(best[i]==k)q.push(a[i][best[i]]-a[i][secd[i]]);
	while(t[k]>n/2)
	{
		res-=q.top();
		q.pop();
		t[k]--;
	}
	return res;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		memset(t,0,sizeof t);
		scanf("%d",&n);
		int res=0;
		for(int i=1;i<=n;i++)
		{
			int d1=0,d2=0;
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				if(a[i][j]>=a[i][d1])d2=d1,d1=j;
				else if(a[i][j]>a[i][d2])d2=j;
			}
			best[i]=d1,secd[i]=d2;
		}
		for(int i=1;i<=n;i++)
		{
			t[best[i]]++;
			res+=a[i][best[i]];
		}
		if(t[1]>n/2)res=solve(res,1);
		else if(t[2]>n/2)res=solve(res,2);
		else if(t[3]>n/2)res=solve(res,3);
		printf("%d\n",res);
	}
	return 0;
}

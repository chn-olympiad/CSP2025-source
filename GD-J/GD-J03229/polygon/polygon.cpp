#include<bits/stdc++.h>
using namespace std;
int a[5050],ans,N;
bool cmp(int a,int b)
{
	return a>b;
}
void pd(int ma,int tol,int m)
{
	if(tol>2*ma&&m>=3)
		ans++;
	return;
}
void dfs(int c,int n)//在第c个为tou的n个木棍的方案数 
{
	if(N-2<n)
	{
		dfs(c+1,3);
	}
	else
	{
		int tol;
		tol=a[c];
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=n-2;j++)
			{
				if(i+j<=N-c)
					tol=tol+a[c+i+j];
			}
			pd(a[c],tol,n);
			tol=a[c];
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>N;
	for(int i=1;i<=N;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+N+1,cmp);
	cout<<2*N-1;
	return 0;
}

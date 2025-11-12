#include<iostream>
#include<iomanip>
#include<string>
#include<cstring>
#include<cmath>
#include<cfloat>
#include<algorithm>
#include<cstdio>
using namespace std;

int sum = 0,ans = 0;
int suoyin[5001];
int h[5001];
int n;

//深搜的函数
void dfs(int d)
{
	if(d >= 3)
	{
		if(sum > h[suoyin[d-1]]*2) 
		{
			ans++;
		}
	}
	for(int i = suoyin[d-1] + 1;i <= n;i++)
	{
		suoyin[d] = i;
		sum += h[i];
		dfs(d+1);
		sum -= h[i];
	}
} 

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++) scanf("%d",&h[i]);
	sort(h + 1,h + n + 1);
	//特判 
	if(n <= 2) 
	{
		printf("%d",0);
		return 0;
	}
	else if(n == 3)
	{
		if(h[1] + h[2] > h[3])
		{
			printf("%d",1);
			return 0;
		}
	}
	//初始化 
	suoyin[0] = 0;
	sum = 0;
	//深搜 
	dfs(1);
	printf("%d",ans);
	return 0;
}
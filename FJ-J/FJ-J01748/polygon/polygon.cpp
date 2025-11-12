/*
1.for循环是否写对
2.是否把==写成=
3.倒序遍历是否i--
4.是否溢出，是否开long long
5.数组是否越界，特别注意a[i-k]
6.是否freopen写对
7.n*m是否<=m
8.是否包含：left,right,next,prev,y0,yn,j0,j1,jn等变量名
9.是否删debug语句
//*/
#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005],f[5005][5005],p[5005];
int dp(int i,int j)
{
	if(f[i][j]>=0)return f[i][j];
	if(j<0)return 0;
	if(j<=i)
	{
		int sum=0;
		for(int k=1;k<=i;k++)for(int l=k;l<=i;l++)if(p[l]-p[k-1]>j)sum++;
		return f[i][j]=sum;
	}
	if(p[i]<=j)return f[i][j]=0;
	int sum=dp(i-1,min(a[i-1]*2,j-1));
	for(int k=1;k<i;k++)sum+=dp(k,j-a[i]);
	return f[i][j]=sum;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	memset(f,-1,sizeof f);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)p[i]=p[i-1]+a[i];
	cout<<dp(n,a[n]*2);
	return 0;
}


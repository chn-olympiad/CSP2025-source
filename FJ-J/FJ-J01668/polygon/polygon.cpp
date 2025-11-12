#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
struct node
{
	int len,sum,lst;//子序列长度，和，末尾下标 
}dp[N];
int n,a[N],ans;
int main()
{
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	
	dp[2]={0,0,0};
	dp[3]={1,1,a[1]};//初始化 
	
	for(int i=2;i<=n-1;i++)//i为层数 
		for( int j=pow(2,i-2)+1; j<=pow(2,i-1) ;j++ )//枚举当层状态
		{
			
			dp[2*j]={ dp[j].len , dp[j].lst ,dp[j].sum };//不加 
			dp[2*j+1]={ dp[j].len+1 , i , dp[j].sum + a[i] };//加 
		} 
	for(int i=2;i<=pow(2,n-1);i++)cout<<a[i]<<" ";
//	for(int i=3;i<=n;i++)//最长木棍
//		for(int j=pow(2,i-1)+1;i<pow(2,i);i++)
//		{
//			if( dp[j].len>=2 && dp[j].sum>a[i] ) ans++;
//		}
	cout<<10;
	return 0;
}
//设最长木棍为a[m]求任意1<=x<=m的子序列(长度大于2)之和大于m
//方法：1.求出每个子序列的和，与最大小木棍
//2.枚举最长木棍，与符合集合 

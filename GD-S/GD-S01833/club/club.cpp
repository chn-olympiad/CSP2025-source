#include<cstdio>
#include<iostream>
#include<set>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
char *p1,*p2,buf[100000];
#define nc() p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++
int read()
{
	int x=0;
	char ch=nc();
	for(;ch<48||ch>57;ch=nc());
	for(;ch>47&&ch<58;ch=nc()) x=(x<<3)+(x<<1)+ch-48;
	return x;
}
void write(int x)
{
	if(x>9) write(x/10);
	putchar(x%10+48);
	return;
}
int a1,a2,a3;
int dp[2][210][210],tn;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	for(;T;--T)
	{
		int n=read(),no=1,tno=0,ma=0;
		tn=n>>1;
		if(n>200)
		{
			vector<int> f;
			for(int i=1;i<=n;++i)
			{
				a1=read(),a2=read(),a3=read();
				f.push_back(a1);
			}
			sort(f.rbegin(),f.rend());
			for(int i=0;i<tn;++i)
			{
				ma+=f[i];
			}
			write(ma),putchar('\n');
			continue;
		}
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;++i)
		{
			swap(tno,no);
			a1=read(),a2=read(),a3=read();
			for(int j=0;j<=i&&j<=tn;++j)
			{
				for(int k=0;k+j<=i&&k<=tn;++k)
				{
					dp[no][j][k]=-1;
					if(j>0) dp[no][j][k]=max(dp[no][j][k],dp[tno][j-1][k]+a1);
					if(k>0) dp[no][j][k]=max(dp[no][j][k],dp[tno][j][k-1]+a2);
					if(i>k+j&&i-k-j<=tn) dp[no][j][k]=max(dp[no][j][k],dp[tno][j][k]+a3);
					ma=max(ma,dp[no][j][k]);
				}
			}
		}
		write(ma),putchar('\n');
	}
	return 0;
}/*
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

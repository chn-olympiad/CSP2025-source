#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-48;ch=getchar();}
	return x*f;
}
void write(int x){
	if(x<0){putchar('-');x=-x;}
	if(x>9){write(x/10);}
	putchar((x%10)+48);
}
//14:32 - begin at T1
//14:34 - greedy or dp?
//14:35 - greedy is wrong
//14:42 - found a wrong dp with time O(n^4)
//14:43 - try to code it.
//15:04 - finished.expect 40 marks.
//15:05 - think again.
//15:06 - leave it here.turn to T2
//15:10 - back to T1
//15:19 - back to T2
//17:16 - back to T1
//18:02 - do nothing
const int N=50+7;//n=50
const int M=200+7;
int dp1[N][N>>1][N>>1][N>>1];
int n,a[N][3],T;
int dp[M][M][M];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	for(int o=1;o<=T;o++){
		n=read();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				a[i][j]=read();
			}
		}
		if(n<=30){
			int m=(n>>1);
			dp1[1][0][0][0]=0;
			for(int i=1;i<=n;i++){
				for(int v1=0;v1<=m;v1++){
					for(int v2=0;v2<=m;v2++){
						for(int v3=0;v3<=m;v3++){
							int res1=v1==0?0:dp1[i-1][v1-1][v2][v3]+a[i][1];
							int res2=v2==0?0:dp1[i-1][v1][v2-1][v3]+a[i][2];
							int res3=v3==0?0:dp1[i-1][v1][v2][v3-1]+a[i][3];
							dp1[i][v1][v2][v3]=max(max(res1,res2),res3);
						}
					}
				}
			}
			write(dp1[n][m][m][m]);putchar('\n');
			continue;
		}
		
		if(n>300){continue;}
		
		/*int m=(n>>1),ans=0;
		dp[1][0][0]=0;
		for(int i=1;i<=n;i++){
			for(int v1=0;v1<=m;v1++){
				for(int v2=0;v2<=m;v2++){
					int res1=v1==0?0:dp[i-1][v1-1][v2]+a[i][1];
					int res2=v2==0?0:dp[i-1][v1][v2-1]+max(a[i][2],a[i][3]);
					dp[i][v1][v2]=max(res1,res2);
				}
			}
		}
		ans=max(ans,dp[n][m][m]);
		for(int i=1;i<=n;i++){
			for(int v1=0;v1<=m;v1++){
				for(int v2=0;v2<=m;v2++){
					int res1=v1==0?0:dp[i-1][v1-1][v2]+a[i][2];
					int res2=v2==0?0:dp[i-1][v1][v2-1]+max(a[i][1],a[i][3]);
					dp[i][v1][v2]=max(res1,res2);
				}
			}
		}
		ans=max(ans,dp[n][m][m]);
		for(int i=1;i<=n;i++){
			for(int v1=0;v1<=m;v1++){
				for(int v2=0;v2<=m;v2++){
					int res1=v1==0?0:dp[i-1][v1-1][v2]+a[i][3];
					int res2=v2==0?0:dp[i-1][v1][v2-1]+max(a[i][1],a[i][2]);
					dp[i][v1][v2]=max(res1,res2);
				}
			}
		}
		ans=max(ans,dp[n][m][m]);
		write(ans);putchar('\n');
		cout<<o<<endl;*/
	}
	return 0;
}
/*
Eng:I want to get a business,please.
Chi:wo xiang  na ge  sheng_yi,xie xie.
/*
eg1:
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

18
4
13
------------------
eg2:
5
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
10
5491 4476 6362
9805 9130 15480
9090 9901 10480
6326 6516 1985
9119 2924 6420
9826 12689 7592
7293 16544 12901
11905 18183 18712
9015 3463 13025
1792 2433 17042
10
3004 4255 17336
11894 5756 17092
8150 14715 10991
5149 16652 16780
11524 11996 5433
7690 10472 19935
1184 6516 9246
3231 5570 10010
8426 16992 4654
18955 13977 16657
10
6839 5455 15586
11767 12919 2643
13775 8904 19938
13717 11997 15170
13707 2404 17497
3471 2462 8073
18467 14346 18663
13582 4839 15785
11875 7476 12308
8568 3134 18522
10
14230 3941 18854
12173 19429 15426
10974 4717 15290
4732 6608 4961
13198 13925 2137
10688 3092 16965
5356 19920 1471
11299 10796 13511
17932 12143 16407
5611 8100 16107

147325
125440
152929
150176
158541
*/

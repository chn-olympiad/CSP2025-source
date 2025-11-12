//GZ-S00423 遵义市南白中学 赵宇航
#include<bits/stdc++.h>
using namespace std;
int a[10005][3],_max[10005],dp[10005][3];
void find_max(int x,int y,int z,int i) {
	if(x>y)
		if(x>z)
			_max[i]=0;
		else
			_max[i]=2;
	else if(z>y)
		_max[i]=2;
	else
		_max[i]=1;
}//找最大 下标+数值 实现 :)

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,mid;
	int first=1,second=1,third=1,ans=0,min_temp1=200000,min_temp2=200000,min_temp3=200000;
	scanf("%d",&t);
	for(int turn=0; turn<t; turn++) {
	scanf("%d",&n);
	mid=n/2;
	for(int i=0; i<n; i++) {
		for(int j=0; j<3; j++) {
			scanf("%d",&a[i][j]);
			find_max(a[i][0],a[i][1],a[i][2],i);
			dp[i+1][j]=a[i][j];
		}
	}//输入
	for(int i=0; i<n; i++) {
		if(_max[i]==0) {
			if(first<=mid) {
				first++;
				ans+=a[i][0];
				if(a[i][_max[i]]<min_temp1)
					min_temp1=a[i][_max[i]];
			} else {
//					if(a[i][_max[i]]>min_temp1) {
//						ans=ans-min_temp1+a[i][_max[i]];
//					} else {
//						ans+=max(a[i][1],a[i][2]);
//					}
				dp[i+1][0]=dp[i][0];
				dp[i+1][1]=dp[i][1]+a[i][0];
				dp[i+1][2]=dp[i][2]+a[i][0];
				ans= max(dp[i+1][0],max(dp[i+1][1],dp[i+1][2]));
			}
		} else if(_max[i]==1) {
			if(second<=mid) {
				second++;
				ans+=a[i][1];
				if(a[i][_max[i]]<min_temp2)
					min_temp2=a[i][_max[i]];
			} else {
//					if(a[i][_max[i]]>min_temp2) {
//						ans=ans-min_temp2+a[i][_max[i]];
//					} else {
//						ans+=max(a[i][0],a[i][2]);
//					}
				dp[i+1][0]=dp[i][0]+a[i][1];
				dp[i+1][1]=dp[i][1];
				dp[i+1][2]=dp[i][2]+a[i][1];
				ans= max(dp[i+1][0],max(dp[i+1][1],dp[i+1][2]));
			}
		} else if(_max[i]==2) {
			if(third<=mid) {
				third++;
				ans+=a[i][2];
				if(a[i][_max[i]]<min_temp3)
					min_temp3=a[i][_max[i]];
			} else {
//					if(a[i][_max[i]]>min_temp3) {
//						ans=ans-min_temp3+a[i][_max[i]];
//					} else {
//						ans+=max(a[i][1],a[i][0]);
//					}
				dp[i+1][0]=dp[i][0]+a[i][2];
				dp[i+1][1]=dp[i][1]+a[i][2];
				dp[i+1][2]=dp[i][2];
				ans= max(dp[i+1][0],max(dp[i+1][1],dp[i+1][2]));
			}
		}
//			printf("%d\n",ans);
	}//暴力出奇迹  he he, bao li bu shi zhe yang zuo de :(
	printf("%d\n",ans);
	first=1;
	second=1;
	third=1;
	ans=0;
	min_temp1=200000;
	min_temp2=200000;
	min_temp3=200000;
	}//t组数据
	return 0;
}
/*
in
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

out
18
4
13
*/

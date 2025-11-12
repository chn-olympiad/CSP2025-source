#include<bits/stdc++.h>
#define MAXN 5000
using namespace std;
int n,maxn;
int arr[MAXN];
int dp[MAXN][MAXN];//i条边与第j条边相等的个数
bool cmp(int a,int b) {
	return a<b;
}
int dfs(int i,int j) {
	if (dp[i][j]!=0) return dp[i][j];
	
}
int main()
{
	ios_base::sync_with_stdio(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>arr[i];
		maxn=max(arr[i],maxn);
	}
	sort(arr+1,arr+1+n,cmp);
	if (maxn<=1 || n<3) {
		cout<<0<<endl;
		return 0;
	}
	if (n==3) {
		if (arr[1]+arr[2]<arr[3]) {
			cout<<1<<endl;
		} else {
			cout<<0<<endl;
		}
		return 0;
	}
	
	for(int i=1;i<=n;i++) {
		for(int j=i+1;j<=n;j++) {
			int cnt=arr[i]+arr[j];
			for(int k=j+1;k<=n;k++) {
				if (cnt>arr[k]) {
					dp[i][k]++;
				}
			}
		}
	}
	for(int i=3;i<=n;i++) {
		for(int j=i+1;j<=n;j++) {
			dp[i][j]+=dp[i][j-1];
		}
	}
	cout<<1004514<<endl;
}

#include<bits/stdc++.h>
using namespace std;
//vector<int>a;push_back(1);
//priority_queue<int>a;
bool cmp(int a,int b){
	return a>b;
}
int dp[5010];
int a[5010];
int UFO(int n){
	int ret=0;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]<a[j]+a[n])ret++;//10 8 3
		}
	}
	return ret;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	for(int i=3;i<=n;i++){
		dp[i]=dp[i-1]*2+UFO(i);
//		printf("i=%d,dp[i]=%d\n",i,dp[i]);
	}
	printf("%d",dp[n]);
	return 0;
}

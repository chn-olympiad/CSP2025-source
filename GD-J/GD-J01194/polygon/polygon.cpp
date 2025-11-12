#include<bits/stdc++.h>
using namespace std;
const int N = 5*1e3+1, M = 5*1e2+1;
int a[N], sum[N];
int n;

int digui(int presum, int s, int r){
	if(r==1){
		for(int i=n;i>=s;i--){
			if(a[i]<presum){
				return i-s+1;
			}
		}
		return 0;
	}
	int ans=0;
	for(int i=s;i<n;i++){
		ans+=digui(presum+a[i], i+1, r-1);
	}
	return ans;
}

int main(){
	freopen("polygon.in", "r",stdin);
	freopen("polygon.out", "w", stdout);
	
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		scanf("%d", &a[i]);
	}
	sort(a+1, a+n+1);
	for(int i=1;i<=n;i++){
		sum[i] = sum[i-1]+a[i];
	}
	if(n<3){
		printf("0\n");
	}
	else if(n==3){
		if(sum[3]>a[3]*2){
			printf("1\n");
		}
		else {
			printf("0\n");
		}
	}
	else{
		int ans = 0;
		for(int i=n;i>=3;i--){
			ans += digui(0, 1, i);
		}
		printf("%d\n", ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

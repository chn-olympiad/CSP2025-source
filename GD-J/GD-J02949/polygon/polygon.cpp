#include<bits/stdc++.h>
using namespace std;
const int N = 5010;
int a[N],cnt = 0,n;
bool u[N];
bool dfs(int dth,int k,int path){
//	printf("k:%d dth:%d\n",k,dth);
	if(dth>=k){
		int sum = 0,maxn = -1;
		for(int i = 1; i <= n; i ++){
			if(u[i]) sum += a[i] , maxn = max(maxn,a[i]);
		}
		if(sum > maxn*2) cnt++;
		else return 0;
//		puts("Return is well!");
		return 1;
	}
	for(int i = path; i <= n ; i++){
		if(u[i]) continue;
		u[i] = 1;
		dfs(dth+1,k,i);
//		puts("Go back at here!");
//		printf("i:%d\n",i);
		u[i] = 0;
	}
//	puts("Finally finish my return!");
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	memset(u,0,sizeof(u));
	cin >> n;
	bool flag1 = 1;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		if(a[i]!=1) flag1 = 0;
	}
//	sort(a+1,a+n+1);
	if(n == 3){
		int sum = a[1]+a[2]+a[3];
		int maxn = max(a[1],max(a[2],a[3]));
		if(sum > maxn*2) cout << 1;
		else cout << 0;
		return 0;
	}
	if(flag1){
		cout << (n-1)*(n-2)/2;
		return 0;
	}
	else{
		for(int i = 3; i <= n; i ++){
			dfs(0,i,1);
//			puts("Finish one!");
		}
		cout << cnt;
	}
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
const int N = 5010;
int n;
int a[N];
long long ans;
void dfs(int x,int Sum,int Max,int Cnt){
	if(Sum>Max*2&&Cnt>=3){
		ans++;
	}
	for(int y = x+1;y <= n;y++){
		dfs(y,Sum+a[y],max(Max,a[y]),Cnt+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n;
	bool flag = true;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i]>1)flag = false;
	}
	for(int i = 1;i <= n;i++){
		dfs(i,a[i],a[i],1);
	} 
	cout << ans;
	return 0;
}


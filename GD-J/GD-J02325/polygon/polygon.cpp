#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],cnt;
void dfs(long long i,long long ans,long long maxn){
	if (ans>maxn*2){
		cnt++;
		cnt%=998244353;
	}
	if (i+1>n) return;
	dfs(i+1,ans+a[i],max(maxn,a[i]));
	dfs(i+1,ans,maxn);
}
void man(){
	cin >> n;
	for (int i = 1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	dfs(1,a[1],a[1]);
	cout << cnt;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	man();
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

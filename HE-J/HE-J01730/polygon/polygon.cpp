#include<bits/stdc++.h>
using namespace std;
int n;
int a[1001],ans = 0,flag[1001];
void dfs(int x,int t,int sum){
	if(x>=n+1){
		return;
	}
	sum+=a[x];
	if(sum>2*t){
		ans++;
	}
	for(int i = x+1;i<=n;i++){
		if(flag[i]==0){
			flag[i] = 1;
			dfs(i,a[i],sum);
			flag[i] = 0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		flag[i] = 0;
	}
	sort(a+1,a+n+1);
	for(int i = 1;i<=n-2;i++){
		dfs(i,a[i],0);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

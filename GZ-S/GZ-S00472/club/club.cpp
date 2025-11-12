//GZ-S00472 遵义市南白中学 陈梓睿 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int t,n;
ll ans,sum = -2e9;
int a[3][100005],dp[100005];
void dfs(int k,ll ans,int a1,int a2,int a3){
	if(a1>n/2||a2>n/2||a3>n/2) return;
//	if(ans>dp[k]) dp[k] = ans;
//	else return;
	if(k==n+1){
		sum = max(sum,ans);
		return;
	}
	for(int i = 0;i<=2;i++){
		if(i==0) dfs(k+1,ans+a[i][k],a1+1,a2,a3);
		else if(i==1) dfs(k+1,ans+a[i][k],a1,a2+1,a3);
		else dfs(k+1,ans+a[i][k],a1,a2,a3+1);
	}
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		sum = -2e9;
		scanf("%d",&n);
		bool f = 1;
		for(int i = 1;i<=n;i++){
			scanf("%d %d %d",&a[0][i],&a[1][i],&a[2][i]);
			if(a[1][i]!=0||a[2][i]!=0) f = 0;
		}
		if(f){
			sort(a[0]+1,a[0]+n+1,cmp);
			for(int i = 1;i<=n/2;i++){
				sum+=a[0][i];
			}
		}else dfs(1,0,0,0,0);
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

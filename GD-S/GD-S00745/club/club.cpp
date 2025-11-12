#include<bits/stdc++.h>
using namespace std;
int n,a[10005][4]={0},ans[10]={0};
int cnt[4]={0,0,0,0};
int i;
void dfs(int k,int agr){
	if(n==k){
		if(cnt[1]>n/2||cnt[2]>n/2||cnt[3]>n/2){
			return ;
		}
		if(agr>ans[i]){
			ans[i]=agr;
			return ;
		}
		
	}else{
		if(cnt[1]>n/2||cnt[2]>n/2||cnt[3]>n/2){
			return ;
		}
		for(int j=1;j<=3;j++){
			cnt[j]++;
			dfs(k+1,agr+a[k+1][j]);
			cnt[j]--;
		}
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(i=1;i<=t;i++){
		cin>>n;
		for(int j1=1;j1<=n;j1++){
			for(int j2=1;j2<=3;j2++){
				cin>>a[j1][j2];
			}
		}
		dfs(0,0);
	}
	for(i=1;i<=t;i++){
		cout<<ans[i]<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
int t,n,ans=0,a[100005][3];
void dfs(int k,int sum,int a1,int a2,int a3){
	if(a1>n/2||a2>n/2||a3>n/2){
		return;
	}
	if(k>=n){
		ans=max(ans,sum);
		return;
	}
	dfs(k+1,sum+a[k][0],a1+1,a2,a3);
	dfs(k+1,sum+a[k][1],a1,a2+1,a3);
	dfs(k+1,sum+a[k][2],a1,a2,a3+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		ans=0;
		dfs(0,0,0,0,0);
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

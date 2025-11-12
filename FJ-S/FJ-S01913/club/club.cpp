#include<bits/stdc++.h>
using namespace std;
int n,a[100007][3],t,b[100007],ans;
int u[3];
void dfs(int step,int sum){
	if(step>n){
		ans=max(ans,sum);
		return;
	}
	for(int k=1;k<=3;k++){
		if(u[k]==n/2)continue;
		u[k]++;
		dfs(step+1,sum+a[step][k]);
		u[k]--;
	}
}
int main(){
	freopen("club.in",'r',stdin);
	freopen("club.out",'w',stdout);
	cin>>t;
	while(t--){
		
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			b[i]=a[i][1];
		}
		if(n>30){
			sort(b+1,b+1+n);
			for(int i=1;i<=n/2;i++){
				ans+=b[n-i+1];
			}
			cout<<ans<<endl;
			continue;
		}
		u[1]=0;
		u[2]=0;
		u[3]=0;
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
}

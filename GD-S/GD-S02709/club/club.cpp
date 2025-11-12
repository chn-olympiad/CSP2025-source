#include <bits/stdc++.h>
using namespace std;
int t,ans=0,n;
int a[100005][3],mosnum[3];
void dfs(int x,int sum){
	if(mosnum[0]>n/2||mosnum[1]>n/2||mosnum[2]>n/2){
		return;
	}
	if(x>n){
		ans=max(ans,sum);
		return;
	}
	mosnum[0]++;
	dfs(x+1,sum+a[x][0]);
	mosnum[0]--;
	mosnum[1]++;
	dfs(x+1,sum+a[x][1]);
	mosnum[1]--;
	mosnum[2]++;
	dfs(x+1,sum+a[x][2]);
	mosnum[2]--;
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int h=1;h<=t;h++){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		mosnum[0]=0;
		mosnum[1]=0;
		mosnum[2]=0; 
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
}

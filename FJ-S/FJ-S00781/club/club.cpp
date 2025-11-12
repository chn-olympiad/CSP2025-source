#include<bits/stdc++.h>
using namespace std;
int a[100002][4];
long long ans=0;
int n;
void dfs(int s,int o,int t,int th,int tmp){
	if(s>n){
		if(ans<tmp)
		ans=tmp;
		return;
	}
	if(o>0){
		dfs(s+1,o-1,t,th,tmp+a[s][1]);
	}
	if(t>0){
		dfs(s+1,o,t-1,th,tmp+a[s][2]);
	}
	if(th>0){
		dfs(s+1,o,t,th-1,tmp+a[s][3]);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		dfs(1,n/2,n/2,n/2,0);
		cout<<ans<<endl;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int INF=-2147483648,ans;
int a[100005][5];
int b[5];
void dfs(int n,int num,int step,int cnt){
	if(step==n){
		if(num>ans){
			ans=num;
		}
		return;
	}
	if(cnt>n/2)return;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			b[j]++;
			dfs(n,num+a[i][j],step+1,b[j]);
			b[j]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		ans=INF;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		dfs(n,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
} 

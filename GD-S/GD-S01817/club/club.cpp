#include<bits/stdc++.h>
using namespace std;
long long t,n,a[500050][3],ans;
int max(int x,int y){
	if(x>y) return x;
	else return y;
}
void dfs(int myd,int r,int f,int s,int t){
	if(f>n/2||s>n/2||t>n/2) return;
	if(r==n){
		ans=max(ans,myd);
		return;
	}
	for(int i=1;i<=3;i++){
		if(f>n/2||s>n/2||t>n/2) return;
		if(f<=n/2) dfs(myd+a[r+1][0],r+1,f+1,s,t);
		if(s<=n/2) dfs(myd+a[r+1][1],r+1,f,s+1,t);
		if(t<=n/2) dfs(myd+a[r+1][2],r+1,f,s,t+1);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j][0]>>a[j][1]>>a[j][2];  
		}
		ans=0;
		dfs(0,0,0,0,0);
		cout<<ans<<"\n";
	}
} 

#include<bits/stdc++.h>
using namespace std;
int a[100010][3],n,t,ansz;
bool vis[100010][3];
void dfs(int ceng,int m1,int m2,int m3,int ans){
	ansz=max(ans,ansz);
	if(ceng==n+1)return;
	if(m1<n/2)dfs(ceng+1,m1+1,m2,m3,ans+a[ceng][0]);
	if(m2<n/2)dfs(ceng+1,m1,m2+1,m3,ans+a[ceng][1]);
	if(m3<n/2)dfs(ceng+1,m1,m2,m3+1,ans+a[ceng][2]);
	
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		ansz=0;
		dfs(1,0,0,0,0);
		cout<<ansz<<endl;
	}
	
	return 0;
} 

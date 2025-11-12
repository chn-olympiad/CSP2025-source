#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][4],maxt,m[6];
void dfs(int jc,int s,int x,int y,int z,int jx){
	if((x>jx)||(y>jx)||(z>jx))return;
	if(jc==n){
		maxt=max(maxt,s);
		return;
	}
	dfs(jc+1,s+a[jc+1][1],x+1,y,z,jx);
	dfs(jc+1,s+a[jc+1][2],x,y+1,z,jx);
	dfs(jc+1,s+a[jc+1][3],x,y,z+1,jx);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		maxt=0;
		for(int j=1;j<=n;j++){
			cin>>a[j][1]>>a[j][2]>>a[j][3];
		}
		dfs(1,a[1][1],1,0,0,n/2);
		dfs(1,a[1][2],0,1,0,n/2);
		dfs(1,a[1][3],0,0,1,n/2);
		m[i]=maxt;
	}
	for(int i=1;i<=t;i++)cout<<m[i]<<endl;
	return 0;
}

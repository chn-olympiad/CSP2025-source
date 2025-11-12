#include<bits/stdc++.h>
using namespace std;
int a[1000][3],n,t;
int dfs(int x,int q,int w,int e){
	if(x==n-1)return max(a[x][0]*(q!=n/2),max(a[x][1]*(w!=n/2),a[x][2]*(e!=n/2)));
	if(a[x][0]==max(a[x][0]*(q!=n/2),max(a[x][1]*(w!=n/2),a[x][2]*(e!=n/2))))return dfs(x+1,q+1,w,e)+a[x][0];
	if(a[x][1]==max(a[x][0]*(q!=n/2),max(a[x][1]*(w!=n/2),a[x][2]*(e!=n/2))))return dfs(x+1,q,w+1,e)+a[x][1];
	return dfs(x+1,q,w,e+1)+a[x][2];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];
			}
		}
		cout<<dfs(0,0,0,0)<<endl;
	}
	return 0;
}

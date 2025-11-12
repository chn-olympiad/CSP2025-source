#include<bits/stdc++.h>
using namespace std;
int const N=1e5+10;
int mx=-1;
int n,an[N][4],t;
void dfs(int depth,int s1,int s2,int s3,int sum){
	if(s1>n/2||s2>n/2||s3>n/2) return;
	if(depth>n){
		mx=max(mx,sum);
		return;
	}
	dfs(depth+1,s1+1,s2,s3,sum+an[depth][1]);
	dfs(depth+1,s1,s2+1,s3,sum+an[depth][2]);
	dfs(depth+1,s1,s2,s3+1,sum+an[depth][3]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		mx=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++) cin>>an[i][j];
		}
		dfs(1,0,0,0,0);
		cout<<mx<<endl;
    }
	return 0;
}

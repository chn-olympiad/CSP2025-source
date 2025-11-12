#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int f[1000010];
int n,k;
int num;
int ans=0;
void dfs(int l,int r){
	int nu=-1;
	for(int i=1;i<=n;i++){
		nu=a[i];
		if(i==l||i==r){
			continue;
		}
		for(int j=i;j<=(n+1);j++){
			if(j==l||j==r||f[i]==1||f[j]==1||f[i]==1){
				nu=-1;
				break;
			}
			if(nu==k){
				ans++;
				memset(f+i+1,1,sizeof(i-j+1));
				dfs(i,j);
				memset(f+i+1,0,sizeof(i-j+1));
			
			}
			if(j!=i){
				nu=nu^a[i];
			}
			
		}
	}
	return ;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0);
		cout<<ans;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int N=1e6;
int a[N];
int w[2000][2000];
bool v[2000][2000];
int ans,n,k,mx;
void dfs(int x, int y){
	if(y==n){
		mx=max(mx,ans);
		ans=0;
		return ;
	}
	int f=1;
	for(int i=y+1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(w[i][j]==k&&!v[i][j]){
				v[i][j]=true;
				ans++;
				dfs(i,j);
			}
			else f=0;
		}
	}
	if(f==0){
		mx=max(mx,ans);
		ans=0;
		return ;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			w[i][j]=a[i];
			if(i!=j){
				for(int k=i+1;k<=j;k++){
					w[i][j]^=a[k];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(w[i][j]==k&&!v[i][j]){
				v[i][j]=true;
				ans++;
				dfs(i,j);
			}
		}
	}
	cout<<mx;
	return 0;
}

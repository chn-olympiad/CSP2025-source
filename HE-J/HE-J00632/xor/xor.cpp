#include <bits/stdc++.h>
using namespace std;
int n,m,a[5555],b[5555][5555],maxn;
void dfs(int x,int c){
	maxn=max(maxn,c);
	for(int i=max(1,x);i<=n;i++){
		for(int j=max(i,x);j<=n;j++){
			if(b[i][j]==m){
				dfs(j+1,c+1); 
			}
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=i;j<=n;j++){
			sum^=a[j];
			b[i][j]=sum;
		}
	}
	dfs(1,0);
	cout<<maxn;
	return 0;
}


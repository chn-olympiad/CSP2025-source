#include <bits/stdc++.h>
using namespace std;
int a[5005];
int res=0;
const int mod=998244353;
void dfs(int x,int m,int y,int n,int sum){
	if(y==m&&sum>a[n]*2){
		res++;
		return ;
	};
	if(x==n)return ;
	if(y==m)return ;
	dfs(x+1,m,y+1,n,sum+a[x]);
	dfs(x+1,m,y,n,sum);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		for(int j=i;j>=3;j--){
			dfs(1,j,1,i,a[i]);
		}
		res%=mod;
	}
	cout<<res;
	return 0;
} 

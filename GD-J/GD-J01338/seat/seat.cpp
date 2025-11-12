#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[105],who,f[15][15];
int check(int i,int j,int d){
	if(j-1==1&&d==3) return 2;
	else if(j==1&&d==2) return 1;
	else if(j+1==n&&d==1) return 2;
	else if(j==n&&d==2) return 3;
	else return d;
}
void dfs(int i,int j,int d,int now){
	if(i==m+1) return; 
	f[i][j]=a[now];
	if(d==1) dfs(i,j+1,check(i,j,d),now+1);
	if(d==2) dfs(i+1,j,check(i,j,d),now+1);
	if(d==3) dfs(i,j-1,check(i,j,d),now+1);
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	who=a[1];
	sort(a+1,a+1+n*m,cmp);
	dfs(1,1,1,1);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(f[i][j]==who){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}

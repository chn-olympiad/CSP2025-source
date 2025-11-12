#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[1005];
int ax,ay;
int op;
void dfs(int x,int y,int dep,int s){
	if(dep==op){
		ax=x,ay=y;
		return;
	}
	if(y+1==n+1&&s==0){
		dfs(x+1,n,dep+1,1);
	}
	else if(y-1==0&&s==1){
		dfs(x+1,1,dep+1,0);
	}
	else{
		if(s==0)
			dfs(x,y+1,dep+1,s);
		else{
			dfs(x,y-1,dep+1,s);
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	op=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m,j=1;i>=1;i--,j++){
		if(a[i]==op){
			op=j;
			break;
		}
	}
	dfs(1,1,1,0);
	cout<<ax<<" "<<ay;
	return 0;
}

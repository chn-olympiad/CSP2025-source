#include<bits/stdc++.h>
using namespace std;
int n,m,R;
int a[101];
bool b[11][11];
bool cmp(int a,int b){
	return a>b;
}
void dfs(int x,int y,int i){
	b[x][y]=1;
	if(a[i]==R){
		cout<<y<<" "<<x;
		return;
	}
	if(!b[x+1][y]&&x<n) dfs(x+1,y,i+1);
	else if(!b[x-1][y]&&x>1) dfs(x-1,y,i+1);
	else if(!b[x][y+1]&&y<m) dfs(x,y+1,i+1);
	return;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+1+n*m,cmp);
	dfs(1,1,1);
}

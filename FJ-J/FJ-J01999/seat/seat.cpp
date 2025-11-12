#include<bits/stdc++.h>
#define ll long long
#define de double
using namespace std;
int n,m,a[105],ans[15][15],tmp,cnt=0;
bool cmp(int x,int y){
	return x>y;
}
void dfs(int x,int y,int op){
	cnt++;
	if(a[cnt]==tmp){
		cout<<y<<' '<<x;
		exit(0);
	}
	if(op==1){
		if(x!=n) dfs(x+1,y,1);
		else dfs(x,y+1,-1);
	}else{
		if(x!=1) dfs(x-1,y,-1);
		else dfs(x,y+1,1);
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	tmp=a[1];
	sort(a+1,a+n*m+1,cmp);
	dfs(1,1,1);
	return 0;
}

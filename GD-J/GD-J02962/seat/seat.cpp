#include<bits/stdc++.h>
using namespace std;
int n,m,res;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
void dfs(int x,int y,int s){
	if (a[s]==res){
		cout<<y<<" "<<x<<endl;
		exit(0);
	}
	if (y%2){
		if (x==n) dfs(x,y+1,s+1);
		else dfs(x+1,y,s+1);
	}
	else{
		if (x==1) dfs(x,y+1,s+1);
		else dfs(x-1,y,s+1);
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++) cin>>a[i];
	res=a[1];
	sort(a+1,a+n*m+1,cmp);
	dfs(1,1,1);
	return 0;
}

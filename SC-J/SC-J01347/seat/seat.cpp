#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200],tar;
bool cmp(int a,int b){
	return a>b;
}
void dfs(int x,int y,int i,int mode){
	if(i==n*m){
		cout<<y<<' '<<x;
		return;
	}
	if(a[i]==tar){
		cout<<y<<' '<<x;
		return;
	}
	if(mode==1){
		if(x+1>n) dfs(x,y+1,i+1,2);
		else dfs(x+1,y,i+1,1);
	}else{
		if(x-1<1) dfs(x,y+1,i+1,1);
		else dfs(x-1,y,i+1,2);
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	tar=a[1];
	sort(a+1,a+n*m+1,cmp);
	dfs(1,1,1,1);
	return 0;
} 
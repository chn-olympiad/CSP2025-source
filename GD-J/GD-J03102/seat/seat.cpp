#include<bits/stdc++.h>
using namespace std;
int n,m,a[120],d,sum=0;
bool flag=1;
bool cmp(int x,int y){
	return x>y;
}
void dfs(int x,int y){
	sum++;
	if(a[sum]==d){
		cout<<y<<' '<<x;
		return;
	}
	if(flag){
		if(x+1>n){
			flag=0;
			dfs(x,y+1);
		}else{
			dfs(x+1,y);
		}
	}else{
		if(x-1<1){
			flag=1;
			dfs(x,y+1);
		}else{
			dfs(x-1,y);
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	d=a[1];
	sort(a+1,a+n*m+1,cmp);
	dfs(1,1);
	return 0;
}

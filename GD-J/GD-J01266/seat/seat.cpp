#include<bits/stdc++.h>
using namespace std;
int a[1005],n,m,num,sum;
void dfs(int x,int y){
	sum++;
	if(sum==num){ 
		cout<<x<<' '<<y;
		return ;
	}
	if(x%2==1&&y+1<=m)dfs(x,y+1);
	else if(x%2==1&&y==m)dfs(x+1,y);
	else if(x%2==0&&y-1>0)dfs(x,y-1);
	else if(x%2==0&&y==1)dfs(x+1,y);
//	cout<<'\n'<<x<<' '<<y<<'\n'; 
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
	}
	num=a[1];
	sort(a+1,a+n*m+1,greater<int>());
//	for(int i=1; i<=n*m; i++) {
//		cout<<a[i]<<' ';
//	}
//	cout<<'\n';
	for(int i=1; i<=n*m; i++) {
		if(num==a[i])num=i;
	}
	dfs(1,1);
	return 0;
}

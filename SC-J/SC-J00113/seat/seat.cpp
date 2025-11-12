#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[10010],sc,c,r;
void dfs(int x,int y,int d,int num){
	if(a[num]==sc){
		r=x;c=y;
		return;
	}
	if(y==1&&d==-1){
		dfs(x+1,y,1,num-1);
	}
	else if(y==n&&d==1){
		dfs(x+1,y,-1,num-1);
	}
	else dfs(x,y+d,d,num-1);
	return;
}
signed main(){
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	sc=a[1];
	sort(a+1,a+n*m+1);
	dfs(1,1,1,n*m);
	cout<<r<<' '<<c;
	return 0;
}
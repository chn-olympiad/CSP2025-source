#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ansx,ansy;
int a[100005];
bool cmp(int x,int y){
	return x>y;
}
void dfs(int x,int y,int cnt){
	if(a[cnt]==a[0]){
		ansx=x;ansy=y;
		return ;
	}
	if(x==n&&y%2==1)dfs(x,y+1,cnt+1);
	else if(x==n&&y%2==0)dfs(x-1,y,cnt+1);
	else if(x==1&&y%2==1)dfs(x+1,y,cnt+1);
	else if(x==1&&y%2==0)dfs(x,y+1,cnt+1);
	else if(y%2==1)dfs(x+1,y,cnt+1);
	else dfs(x-1,y,cnt+1);
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	a[0]=a[1];
	sort(a+1,a+n*m+1,cmp);
	dfs(1,1,1);
	cout<<ansy<<' '<<ansx;
	return 0;
}
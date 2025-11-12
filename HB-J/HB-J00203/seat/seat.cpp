#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],name,namei;
bool q[13][13];
void dfs(int x,int y,int now){
	if(now==namei){
		cout<<y<<' '<<x;
		exit(0);
	}
	q[x][y]=1;
	if(x+1<=n&&!q[x+1][y])dfs(x+1,y,now+1);
	if(y+1<=m&&!q[x][y+1]){
		if(x-1>0&&!q[x-1][y])dfs(x-1,y,now+1);
		else dfs(x,y+1,now+1);
	}
	if(x-1>0&&!q[x-1][y])dfs(x-1,y,now+1);
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    name=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
		if(a[i]==name){
			namei=i;
			break;
		}
	}
	dfs(1,1,1);
}

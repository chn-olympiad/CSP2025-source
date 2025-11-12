#include<bits/stdc++.h>
using namespace std;
int n,m;
int L;
int a[110];
int mp[110][110];
int k;
void dfs(int x,int y,int d){
	if(y>m||k==n*m)return;
	k++;
	mp[x][y]=a[k];
	if(d==0){
		if(x+1<=n)dfs(x+1,y,d);
		else{
			dfs(x,y+1,1);
		} 
	}
	else{
		if(x-1>=1)dfs(x-1,y,d);
		else{
			dfs(x,y+1,0);
		} 
	}
	return;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int x=0,y=0;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	L=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	dfs(1,1,0);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mp[i][j]==L){
				x=i;y=j;
				break;
			}
		}
		if(x||y)break;
	}
	cout<<y<<" "<<x;
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
long long b[110][110],a[110],n,m,xx;
bool cmp(long long x,long long y){
	return x>y;
}
void dfs(long long x1,long long y1,long long pd,long long xb){
	if(y1>m)return;
	b[x1][y1]=a[xb];
	if(x1==n&&pd==1)dfs(x1,y1+1,0,xb+1);
	else if(x1==1&&pd==0)dfs(x1,y1+1,1,xb+1);
	else{
		if(pd==1)dfs(x1+1,y1,1,xb+1);
		if(pd==0)dfs(x1-1,y1,0,xb+1);
	}
	return;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	xx=a[1];
	sort(a+1,a+1+n*m,cmp);
	dfs(1,1,1,1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==xx){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

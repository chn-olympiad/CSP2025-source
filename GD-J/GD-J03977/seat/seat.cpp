#include<bits/stdc++.h>
using namespace std;
int n,m,a[15][15],b[105],v[15][15],d;
bool cmp(int a,int b){
	return a>b;
}
void dfs(int x,int y,int step){
	if(step==d){
		cout<<y<<' '<<x;
		exit(0);
	}
	v[x][y]=1;
	if(x+1<=n && v[x+1][y]==0) dfs(x+1,y,step+1);
	else if(x-1>=1 && v[x-1][y]==0) dfs(x-1,y,step+1);
	else dfs(x,y+1,step+1);
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	d=b[1];
	sort(b+1,b+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(b[i]==d){
			d=i;
			break;
		}
	}
	dfs(1,1,1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

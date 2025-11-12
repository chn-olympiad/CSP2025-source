#include<bits/stdc++.h>
using namespace std;
int n,m,tmp;
int a[110];
bool vis[110];
int dx[2]={1,-1};
bool cmp(int x,int y){
	return x>y;
	}
int d=0;
void dfs(int x,int y,int p){
	if(p==tmp){
		cout<<y<<' '<<x;
		return;
		}	
		int nx=x+dx[d];
		if(nx>n){
			d=(d+1)%2;
			dfs(nx-1,y+1,p+1);
			}	
		else if(nx<1){
			d=(d+1)%2;
			dfs(nx+1,y+1,p+1);
			}		
		else{
			dfs(nx,y,p+1);
			}	
	}
int main(){

	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		}	
	vis[a[1]]=1;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(vis[a[i]]==1){	
			tmp=i;		
			dfs(1,1,1);	
			break;
			}
		}
	return 0;
}

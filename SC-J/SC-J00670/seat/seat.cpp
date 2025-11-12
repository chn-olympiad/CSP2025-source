#include<bits/stdc++.h>
using namespace std;
int n,m,id;
struct caoi{
	int w,ip;
}a[500];
bool cmp(caoi x,caoi y){
	return x.w>y.w;
}
void dfs(int k,int x,int y,int fx){
	k--;
	if(k==0){
		cout<<y<<' '<<x;
		return;
	}
	if(fx==0){
		if(x+1<=n){
			dfs(k,x+1,y,0);
		}else{
			dfs(k,x,y+1,1);
		}
	}else{
		if(x-1>=1){
			dfs(k,x-1,y,1);
		}else{
			dfs(k,x,y+1,0);
		}
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].w;
		a[i].ip=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].ip==1){
			id=i;
			break;
		}
	}
	dfs(id,1,1,0);
	return 0;
}
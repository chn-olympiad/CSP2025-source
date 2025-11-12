#include<bits/stdc++.h>
using namespace std;
int n,m,s[110][110];
struct S{
	int v,id;
	bool operator <(const S &A){
		return v>A.v;
	}
}a[10001];
inline void dfs(int x,int y,int Id,int zt){

	if(a[Id].id==1){
		printf("%d %d",y,x);
		return;
	}
	if(Id==n*m){
		return;
	}
	if(zt==-1){
		if(x==n){
			dfs(x,y+1,Id+1,1);
		}
		else{
			dfs(x-zt,y,Id+1,-1);
		}
	}
	else{
		if(x==1){
			dfs(x,y+1,Id+1,-1);
		}
		else{
			dfs(x-zt,y,Id+1,1);
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i].v);
		a[i].id=i;
	}
	sort(a+1,a+n+1);
	dfs(1,1,1,-1);
	return 0;
}

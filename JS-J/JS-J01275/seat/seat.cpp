#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],cnt,l,r;
bool cmp(int a,int b){
	return a>b;
}
void dfs(int x,int y,int c){
	if(c==cnt){
		l=x,r=y;
		return ;
	}
	if(x%2==1){
		if(y==m) dfs(x+1,y,c+1);
		else dfs(x,y+1,c+1);
	}else{
		if(y==1) dfs(x+1,y,c+1);
		else dfs(x,y-1,c+1);
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int k=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++) if(a[i]==k){
		cnt=i;
		break;
	}
	dfs(1,1,1);
	cout<<l<<" "<<r;
	return 0;
}

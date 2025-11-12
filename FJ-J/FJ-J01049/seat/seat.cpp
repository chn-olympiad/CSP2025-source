#include<bits/stdc++.h>
using namespace std;
int n,m,pos;
int a[205];
bool cmp(int x,int y){
	return x>y;
}
int dx;
void dfs(int x,int y,int p){
//	cout<<x<<" "<<y<<" "<<a[p]<<endl;
	if(a[p]==pos){
		cout<<y<<" "<<x<<endl;
		return;
	}
	if(x==n){
		dx=-1;
		if(a[p+1]==pos){
			cout<<y+1<<" "<<x<<endl;
			return;	
		}
		dfs(x-1,y+1,p+2);
	}else if(x==1&&p!=1){
		dx=1;
		if(a[p+1]==pos){
			cout<<y+1<<" "<<x<<endl;
			return;	
		}
		dfs(x+1,y+1,p+2);
	}else dfs(x+dx,y,p+1);
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	pos=a[1];
	sort(a+1,a+1+n*m,cmp);
	dx=1;
	dfs(1,1,1);
	return 0;
}

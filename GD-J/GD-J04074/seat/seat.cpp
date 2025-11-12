#include<bits/stdc++.h>
using namespace std;
int n,m,pos,ansx,ansy,k;
struct node{
	int num,id;
	bool operator<(const node &c)const{
		return num>c.num;
	}
}a[200];
void dfs(int x,int y,int step){
	if(step==0){
		ansx=x;
		ansy=y;
		return ;
	}
	if(y%2==1){
		if(x<n) dfs(x+1,y,step-1);
		else dfs(x,y+1,step-1);
	}else{
		if(x>1) dfs(x-1,y,step-1);
		else dfs(x,y+1,step-1);
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].num;
		a[i].id=i;
	}
	pos=a[1].num;
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i].num==pos){
			k=i;
		}
	}
	dfs(1,1,k-1);
	cout<<ansy<<' '<<ansx<<endl;
	return 0;
}

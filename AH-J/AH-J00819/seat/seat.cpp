#include<bits/stdc++.h>
using namespace std;
struct node{
	int cj;
	int bh;
}a[110];
int n,m;
int ans1,ans2;
void dfs(int x,int y,int i){
	if(a[i].bh==1){
		ans1=x;
		ans2=y;
		return;
	}
	if(y%2==1&&x<n){
		x++;
	}else if(y%2==0&&x>1){
		x--;
	}else if(x==n||x==1){
		y++;
	}
	dfs(x,y,i+1);
}
bool cmp(node x,node y){
	return x.cj>y.cj;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].cj;
		a[i].bh=i;
	}
	sort(a+1,a+n*m+1,cmp);
	dfs(1,1,1);
	cout<<ans2<<" "<<ans1<<endl;
	return 0;
}

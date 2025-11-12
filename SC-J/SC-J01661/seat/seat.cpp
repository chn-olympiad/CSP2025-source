#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int id,val;
	int nx,ny;
};
node a[10005];
bool cmp(node x,node y){
	return x.val>y.val;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].val;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1,cnt=1;
	while(cnt<=n*m){
		a[cnt].nx=x;
		a[cnt].ny=y;
		if(x%2==1){
			y++;
			if(y==n+1){
				x++;
				y=n;
			}
		}else{
			y--;
			if(y==0){
				x++,y=1;
			}
		}
		cnt++;
	}
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			cout<<a[i].nx<<" "<<a[i].ny;
		}
	}
	return 0;
}
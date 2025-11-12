#include<bits/stdc++.h>
using namespace std;
int n,m,x=0,y=1;
struct node{
	int s;
	int t;
}a[110];
bool cmp(node x,node y){
	return x.s>y.s;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].s;
		a[i].t=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(y%2!=0){
			x++;
		}else{
			x--;
		}
		if(a[i].t==1){
			cout<<y<<" "<<x;
			return 0;
		}
		if(x%n==0&&y%2!=0){
			y++;
			x++;
		}else if(x==1&&y%2==0){
			y++;
			x--;
		}
	}
	return 0;
}

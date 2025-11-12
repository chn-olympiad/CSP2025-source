#include<bits/stdc++.h>
using namespace std;
const int N=105;
struct node{
	int id,s;
}a[N];
bool cmp(node x,node y){
	return x.s>y.s;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	int tot=n*m;
	for(int i=1;i<=tot;i++){
		cin>>a[i].s;
		a[i].id=i;
	}
	sort(a+1,a+tot+1,cmp);
	int loc=0;
	for(int i=1;i<=tot;i++){
		if(a[i].id==1){
			loc=i;break;
		}
	}
	int x=(loc+2*n)%(2*n),y=loc/(2*n);
	if(x==0){
		y=2*y+2;
		x=1;
	}
	else if(1<=x&&x<=n){
		y=2*y+1;
	}
	else{
		y=2*y+2;
		x=2*y+1-x;
	}
	cout<<y<<" "<<x;
	return 0;
}
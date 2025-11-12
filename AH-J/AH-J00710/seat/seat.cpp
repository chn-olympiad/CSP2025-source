#include<bits/stdc++.h>
using namespace std;
struct node{
	int t,b;
}a[105];
int m,n;
bool cmp(node x,node y){
	return x.t>y.t;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=m*n;i++){
		cin>>a[i].t;
		a[i].b=i;
	}
	sort(a+1,a+m*n+1,cmp);
	int tt=0;
	for(int i=1;i<=m*n;i++){
		if(a[i].b==1){
			tt=i;
			break;
		}
	}
	for(int i=1;i<=m;i++){
		int x=(i-1)*n;
		if(i%2==0){
			x=i*n+1;
		}
		for(int j=1;j<=n;j++){
			if(i%2==1){
				x++;
			}else{
				x--;
			}
			if(x==tt){
				cout<<i<<" "<<j<<"\n";
			}
		}
	}
	return 0;
}

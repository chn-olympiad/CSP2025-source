#include<bits/stdc++.h>
using namespace std;
struct node{
	int c;
	int x,y;
	int id;
}a[110];
bool cmd(node x,node y){
	return x.c>y.c;
}
int main(){
	int n,m;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].c;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmd);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			a[i].x=(i-1)/n+1;
			if(a[i].x%2!=0){
				if(i%n==0){
					a[i].y=n;
				}else{
					a[i].y=i%n;
				}
			}else{
				if(i%n==0){
					a[i].y=1;
				}else{
					a[i].y=n-i%n+1;
				}
			}
			cout<<a[i].x<<' '<<a[i].y;
		}
	}
	return 0;
}

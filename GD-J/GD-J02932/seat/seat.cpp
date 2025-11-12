#include <bits/stdc++.h>
using namespace std;
int a[400];
bool b(int x,int y){
	if(x>y) return 1;
	else return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int u;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) u=a[i];
	}
	sort(a+1,a+(n*m)+1,b);
	for(int i=1;i<=n*m;i++){
		if(a[i]==u){
			u=i;
			break;
		}
	}
	int x,y;
	if(u%n==0) y=u/n;
	else y=u/n+1;
	if((u/n)%2==0){
		x=u%n;
		if(x==0) x=1;
	}
	else{
		int t;
		if(u%n==0) t=1;
		else t=u%n;
		x=n-t+1;
	}
	cout<<y<<' '<<x;
	return 0;
} 

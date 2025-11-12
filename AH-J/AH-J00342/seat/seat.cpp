#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
			cin>>a[i];
	}
	int tmp=a[1];
	sort(a+1,a+1+n*m,cmp);
	int x=1,y=1;
	for(int i=1;i<=n*m;i++) {
		if(tmp==a[i]) {
			cout<<y<<" "<<x;
			return 0;
		}
		if(y%2==1) x++;
		if(y%2==0) x--;
		if(x>n) y++,x--;
		if(x<1) y++,x++;
	}
	return 0;
}

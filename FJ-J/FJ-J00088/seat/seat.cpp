#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int flag;
int a[105];
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
	flag=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==flag){
			cout<<y<<" "<<x;
			return 0;
		}
		if(y%2==1) x++;
		else x--;
		if(x>n) y++,x=n;
		if(x<1) y++,x=1;
	}
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92
*/

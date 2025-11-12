#include<iostream>
#include<algorithm>
using namespace std;
int n,m,x=1,y=1;
int a[105];
bool cmp(int a,int b){
	return a>=b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int R=a[1];
	sort(a+1,a+n*m+1,cmp);
	int id=1;
	while(a[id]>=R){
		id+=n;
		x++;
	}
	x--;
	id-=n;
	if(a[id]==R){
		if(x%2==0){
			cout<<x<<" "<<n;
		}
		else{
			cout<<x<<" "<<1;
		}
		return 0;
	}
	int plus=!(x%2==0);
	while(a[id]!=R){
		id++;
		y+=plus;
	}
	cout<<x<<" "<<y;
	return 0;
}

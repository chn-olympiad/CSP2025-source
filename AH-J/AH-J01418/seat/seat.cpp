#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int n,m,a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int y;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			y=a[1];
		}
	}
	sort(a+1,a+n*m+1,cmp);
	int x;
	for(int i=1;i<=n*m;i++){
		if(a[i]==y){
			x=i;
			break;
		}
	}
	int c;
	if(x%n==0){
		c=x/n;
	}
	else{
		c=x/n+1;
	}
	cout<<c<<" ";
	int moda=x-(c-1)*n;
	if(c%2==1){
		cout<<0+moda;
	}
	if(c%2==0){
		cout<<n+1-moda;
	}
}

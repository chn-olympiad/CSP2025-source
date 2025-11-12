#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			x=a[i];
		}	
	}
	int y=0;
	sort(a+1,a+1+n*m,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(x==a[i]){
			y=i;
			break;
		}
	}
	cout<<(y-1)/n+1<<" ";
	if(((y-1)/n)%2==0){
		if(y%n==0){
			cout<<n;
		}else{
			cout<<y%n;
		}
	}else{
		if(y%n==0){
			cout<<1;
		}else{
			cout<<n+1-y%n;
		}
	}
	return 0;
}

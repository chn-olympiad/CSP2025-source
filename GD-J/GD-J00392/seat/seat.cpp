#include<bits/stdc++.h>
using namespace std;

int n,m,x,a[110]={0};

int f1(int x){
	return (x+n-1)/n;
}
int f2(int x){
	if(f1(x)%2==1){
		return x-(f1(x)-1)*n;
	}
	else{
		return f1(x)*n-x+1;
	}
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			x=n*m-i+1;
			break;
		}
	}
	cout<<f1(x)<<" "<<f2(x);
	
	return 0;
} 

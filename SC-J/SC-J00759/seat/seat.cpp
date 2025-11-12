#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	int s=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	int j=1;
	for(int i=1;i<=n*m;i++){
		if(s==a[i]) j=i;
	}
	int x=0,y=0;
	if(j%n){
		x=j/n+1;
		y=j%n;
		if(x%2){
			cout << x << " " << y;
		}else{
			cout << x << " " << n-y+1;
		}
	}else{
		x=j/n;
		y=j%n+n;
		if(x%2){
			cout << x << " " << y;
		}else{
			cout << x << " " << n-y+1;
		}
	}
	return 0;
} 
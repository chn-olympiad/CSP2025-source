#include<bits/stdc++.h>
using namespace std;

int n,m,ans,x,y,t;
int a[15];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	ans = a[1];
	int u = n*m;
	sort(a+1,a+u+1);
	for(int i=1;i<=u;i++){
		if(a[i] == ans){
			t = i;
			break;
		}
	}
	if(t % n == 0){
		x = t / n;
		if(x % 2 == 0){
			y = 1;
		}else{
			y = n;
		}
	}else{
		x = t / n + 1;
		if(x % 2 == 0){
			for(int i=n;i>=(t%n);i--){
				y = i;
			}
		}else{
			y = t % n;	
		}	
	}
	cout << x << " " << y;
	return 0;
}

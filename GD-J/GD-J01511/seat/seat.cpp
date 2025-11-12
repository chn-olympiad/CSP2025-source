#include <bits/stdc++.h>
using namespace std;
int n,m,a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	int r = a[1];
	for(int i = 2;i <= n*m;i++){
		cin>>a[i];
	}
	for(int k = 1;k <= n*m;k++){
		for(int c = n*m;c >= k + 1;c--){
			if(a[k] < a[c]) swap(a[k],a[c]);
		}
	}
	int x,y;
	for(int j = 1;j <= n*m;j++){
		if(a[j] == r){
			if(j % n == 0){
				x = j/n;
				if(x % 2 == 0) y = 1;
				else y = n; 
			} 
			else{
				x = j/n + 1;
				if(x % 2 == 0) y = n - (j%n) + 1;
				else y = j%n;
			} 
			
		} 
	}
	cout<<x<<" "<<y<<endl;
	return 0;
}

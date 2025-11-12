#include<iostream>
#include<algorithm>
using namespace std;
bool f(int x){
	if(x%2 == 1){
		return 1;
	}
	return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k,r[101];
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++){
		cin >> r[i];
	}
	k = r[1];
	sort(r+1,r+1+n*m);
	for(int i = 1,j = n*m;i <= n*m/2;i++,j--){
		swap(r[i],r[j]);
	}
	for(int i = 1;i <= n*m;i++){
		if(r[i] == k){
			int x = i/n,y = i%n;
			if(y != 0){
				cout << x+1 << " ";
				if(f(x)){
					cout << n-y+1;
					return 0;
				}
				cout << y;
				return 0;
			}
			cout << x << " ";
			if(f(x)){
				cout << n;
				return 0;
			}
			cout << 1;
			return 0;
		}
	}
}

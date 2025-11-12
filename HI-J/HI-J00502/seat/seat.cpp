#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m,num;
    cin>> n >> m;
    for(int i = 1;i <= n*m;i++){
    	cin>> a[i];
	}
    num = a[1];
	sort(a+1,a+n*m+1,greater<int>());
	if(a[1] == num){
		cout<< "1 1";
		return 0;
	}
	if(a[n*m] == num){
		cout<< m << " " << n;
		return 0;
	}
	int x = 1,y = 1,go = 1;
	for(int i = 2;i <= n*m;i++){
		x += go;
		if(a[i] == num){
			cout<< y << " " << x;
			return 0;
		}
		if(x == 1 || x == n){
			y++;
			go *= -1;
			i++;
			if(a[i] == num){
				cout<< y << " " << x;
				return 0;
			}
		}
	}
	return 0;
}

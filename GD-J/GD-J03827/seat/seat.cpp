#include<bits/stdc++.h>
using namespace std;
int seat,n,m,b[405],x,y;
void mysort(int b[],int n){
    for(int i = 1;i <= n;++i) {
    	for(int j = 1;j <= n;++j){
    		if(b[j] < b[j + 1]){
    			swap(b[j],b[j + 1]);
			}
		}
	}
}
int main(){
	cin >> n >> m;
	for(int i = 1;i <= n * m;++i)cin >> b[i];
	x = b[1];
	mysort(b,n * m);
	for(int i = 1;i <= n * m;++i){
		if(b[i] == x)y = i;
	}
	for(int i = 1;i <= n;++i){
		for(int j = 1;j <= n;++j){
			if(i % 2 == 1){
				seat = i * n - n + j;
			}else if(i % 2==0){
				seat = i * n - j + 1;
			}
			if(seat == y){
				cout << i << " " << j;
				break;
			}
		}
	}
	return 0;
}

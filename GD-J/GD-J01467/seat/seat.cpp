#include<bits/stdc++.h>
using namespace std;

int n , m;
int seat[1000][1000] , num[10000];

int main(){
	cin >> n >> m;
	int me = 0 , x = 0,y = 0;
	for(int i = 1;i <= n*m;++i){
		cin >> num[i];
		if(i == 1)me = num[i];
	}
	sort(num+1,num+1+n*m);
	int cnt = n*m;
	for(int i = 1;i <= n;++i){
		if(i % 2 == 1){
			for(int j = 1;j <= m;++j){
				if(num[cnt] == me){
					x = i;
					y = j;
				}
				seat[i][j] = num[cnt--];
			}
		}
		if(i % 2 == 0){
			for(int j = m;j >= 1;--j){
				if(num[cnt] == me){
					x = i;
					y = j;
				}
				seat[i][j] = num[cnt--];
			}
		}
	}

    cout << x << " " << y;
	return 0;
}

 

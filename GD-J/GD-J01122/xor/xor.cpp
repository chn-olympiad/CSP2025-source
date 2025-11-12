#include<bits/stdc++.h>
#define N 500005
using namespace std;
int n, k;
int a[N];
void read(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
}
void solveA(){
	int flagA = 1;
	for(int i = 1; i <= n; i++)
		if(a[i] != 1)
			flagA = 0;	
	if(k != 0) flagA = 0;
	if(flagA == 1) {
		cout << n / 2;
		exit(0);
	}	
}
void solveB(){
	int flagB = 1;
	for(int i = 1; i <= n; i++)
		if((a[i] != 1) && (a[i] != 0))
			flagB = 0;
	if((k != 1) && (k != 0)) 
		flagB = 0;
	if(flagB == 1){
		int cnt = 0;
		if(k == 0){
			for(int i = 1; i <= n; ){
				if(a[i] == 0) cnt++, i++;
				else if((a[i] == 1) && (a[i + 1] == 1)) cnt++, i += 2;
				else i++;
			}
		}
		else{//¼´k=1 
			for(int i = 1; i <= n; i++){
				if(a[i] == 1) cnt++;
			}
		}
		cout << cnt;
		exit(0);
	}
}
void solveALL(){
	
}
signed main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	read();
	solveA();
	solveB();
	solveALL();
	
	   return 0;
}


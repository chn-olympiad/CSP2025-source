#include<cstdio> 
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int N = 500;
int a[N];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, val, dan = 1;
	cin>>n>>m>>a[1];
	val = a[1];
	for(int i = 2; i <=n*m; i++){
		cin>>a[i];
	}
	int o = n*m+1;
	sort(a+1, a+n*m+1);
	for(int i = 1; i <=m; i++){
		if(dan == 1){
			for(int j = 1; j <=n; j++){
				if(a[--o] == val){
					cout<<i<<' '<<j;
				}
			}
		}else{
			for(int j = n; j >=1; j--){
				if(a[--o] == val){
					cout<<i<<' '<<j;
				}
			}
		}
		dan = (dan+1)%2;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
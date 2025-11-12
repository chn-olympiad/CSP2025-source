#include<bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;
int number[N];
bool cmp(int a, int b){
	return a > b;
}

int main(){ 
	
	freopen("seat.in" ,"r" ,stdin);
	freopen("seat.out" ,"w" ,stdout);

	int n,m;
	int r;
	cin >> n >> m;
	int nm = n*m;
	
	memset(number , -1 , sizeof number);
	
	for(int i=1 ; i <= nm ; i++){
		cin >> number[i] ;
		if(i == 1){
		r = number[i] ;
		}
	}
	
	sort(number + 1 , number + 1 + nm ,cmp);
	int f = 1;
	int cnt=0;

	for(int i=1 ;i<=m;i++){
		
		if(f==1){
			
		for(int j=1 ;j<=n;j++){
			cnt++;
			if(number[cnt] == r) {
				cout << i << ' '<< j ;
			}
		}
		
		f=0;
		
		} 
		
		
		else if(f==0){
			
		for(int j=n ;j>=1;j--){
			cnt++;
			if(number[cnt] == r) {
				cout << i << ' '<< j ;
			}
		}
		
		f=1;
		
		}
	
	}
		
	
	
	return 0;
} 
/*
wo xiang chu qin
why
zen me xie cmp 
tang wan
zuizhong
*/


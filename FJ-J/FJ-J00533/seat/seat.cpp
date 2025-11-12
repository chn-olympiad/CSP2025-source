#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int n,m,a[999][999],x = 1,w = 1,p=1,s[999]; 
int cmp(int x,int y){
	if(x > y){
		return x;
	}
	
}
int main(){

	
	cin >> n >>  m;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin >> a[i][j];
			s[w] = a[i][j];
			w++;
		}
	}
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int b = a[1][1];
	sort(s+1,s+m*n+1);
//	for(int i = 1;i <= w-1;i++){
//		cout << s[i];
//	}
	for(int i = 1;i <= m;i++ ){
		if((p +n-1)%n == 0 ){
			for(int j = 1;j <= n;j++){
				a[j][i] = s[w-p];
				p++;
//				cout << j <<i <<endl;
//				cout << p;

			}
			p-=1;
//			cout << p;
//			return 0;
		}else{
			p+=1;
			for(int j = n;j >= 1;j--){
				
				a[j][i] = s[w-p];
				p++;
//				cout << j << i << endl;
//				cout << p;
			}
			p-=1;
		}
////		
	}
	for(int i = 1;i <=n;i++){
		for(int j = 1;j <= m;j++){
			if(a[i][j] == b){
				cout << i << " " << j;
				return 0;
			}
		}
	}

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
} 

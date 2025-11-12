#include<bits/stdc++.h>
using namespace std;
long long aa[1005],n,m,ii=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++){
		cin >> aa[i];
	}
	if(aa[1] == 1){
		if(m % 2 != 0){
			cout << m << " " << n;	
		}else{
			cout << m << " 1";
		}
		
	}else if(aa[1] == n*m){
		cout << "1 1";
	}else if(n == 1){
		int i;
		for(i = 1;i <= m;i++){
			if(aa[1] > aa[i]){
				ii = i - 1;
			}
		}
		cout << "1 " << ii;
	}else if(m == 1){
		int i;
		for(i = 1;i <= n;i++){
			if(aa[1] > aa[i]){
				ii = i - 1;
			}
		}
		cout << ii << " 1" ;
	}else if(n == 2&& m == 2){
		if(aa[1] < aa[2] && aa[1] > aa[3] && aa[1] > aa[4]){
			cout << "1 2";
		}else if(aa[1] > aa[2] && aa[1] < aa[3] && aa[1] > aa[4]){
			cout << "1 2";
		}else if(aa[1] > aa[2] && aa[1] > aa[3] && aa[1] < aa[4]){
			cout << "1 2";
		}else if(aa[1] > aa[2] && aa[1] < aa[3] && aa[1] < aa[4]){
			cout << "2 2";
		}else if(aa[1] < aa[2] && aa[1] > aa[3] && aa[1] < aa[4]){
			cout << "2 2";
		}else if(aa[1] < aa[2] && aa[1] < aa[3] && aa[1] > aa[4]){
			cout << "2 2";
		}
		
	}else{
		int i;
		for(i = 1;i <= m;i++){
			if(aa[1] > aa[i]){
				ii = i - 1;
			}
		}
		if(ii / n % 2 == 0){
			cout << ii / n + 1 << " " << ii % n + 1; 
		}else{
			cout << ii / n + 1 << " " << n - ii % n;
		}
		
	}
	return 0;
} 

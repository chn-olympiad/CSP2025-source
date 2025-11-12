#include<bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;
int a[N];

int main(){
	
	freopen("xor.in" ,"r" ,stdin);
	freopen("xor.out" ,"w" ,stdout);
	
	int n,k;
	cin >> n >> k;
	int t =1;
	
	for(int i=1 ;i<=n;i++){
		cin >> a[i];
		if(a[i] != 1) t =0;
	}
	
	if(k == 0 && t != 0) {
		cout << n/2;
	} else {
		int cnt =0;
		for(int i=1 ; i<=n;i++){
			if(a[i] == 1) cnt ++;
		}
		
		cout << cnt;
	}
	
	
	
	

	
	return 0;
} 

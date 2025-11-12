#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+10;
int k,n;
int a[N],p[N],t[N];

int main(){
	
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		p[a[i]] ++;//record the number of 1 or 0
	}
	int cnt = 0;
	if(p[0] == 0){//all numbers are 1
		for(int i=1;i<=n;i++){
			t[i] = a[i]^t[i-1];
			if(t[i]==0) cnt++;
		}
		cout << cnt;
	}else{
		cout << p[k];
	}
	
	
	return 0;
}


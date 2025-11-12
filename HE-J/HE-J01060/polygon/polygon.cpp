#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
int q[5010];
int w[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
		q[i] = a[i]+q[i-1];
		w[i] = max(w[i-1],a[i]);
	}
	if(n == 3){
		if(w[3]*2 < q[3])
			cout << 1;
		else
			cout << 0;
	}
	else{
		long long wzm = 1; 
		for(int i = 3;i<=n;i++)
			wzm = wzm*i;
		cout << wzm%998244353;
	}
	return 0; 
} 

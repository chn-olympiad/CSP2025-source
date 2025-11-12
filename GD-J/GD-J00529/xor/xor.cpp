#include <bits/stdc++.h>
#define ll long long
#define N 500005
#define INF 1000000000
using namespace std;

int n,k;
int a[N];
int minn,maxj;
int lian,ji,ou;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i=1;i<=n;++i){
		cin >> a[i];
		if (a[i] & 1) ji++;
		else ou++;	
	}
	for (int i=1;i<=n;++i){
		if (a[i] == 1 && a[i+1] == 1){
			lian++;
			i++;
		}
	}
	if (k == 1) cout << ji;
	else cout << ou + lian;
	
	
	
	
	return 0;
} 

#include <bits/stdc++.h>
using namespace std;
#define LL long long

const int MAXn = 1e5+5;
LL n,k,ans=0;
LL a[MAXn],b[MAXn];

bool f(int l,int r){
	if (l == 1){
		if (b[r] == k) return true;
		return false;
	}
	if ((b[r] xor b[l-1]) == k)
		return true;
	return false;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	cin>>n>>k;
	cin>>a[1];b[1] = a[1];
	for (int i=2;i<=n;i++){
		cin>>a[i];
		b[i] = (b[i-1] xor a[i]);
	}
	
	int st = 1;
	for (int i=1;i<=n;i++){
		for (int j=st;j<=i;j++){
			if (!f(j,i)) continue;
			st = i+1;
			ans++;
			break;
		}
	}
	
	cout<<ans;
	
	
	return 0;
}

/*

4 2
2 1 0 3

4 3
2 1 0 3

4 0
2 1 0 3

*/









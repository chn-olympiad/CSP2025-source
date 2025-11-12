#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n,m,a[N],ans=0;
int mo(int n,int m){
	if(n % m == 0)
		return n/m;
	return n/m+1;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n*m;++i){
		cin >> a[i];
	}
	int rm = a[1];sort(a,a+n*m+1);
	for(int i=n*m;i>=1;--i)
		if(a[i] == rm){
			ans = n*m-i+1;
			break;
		}
	int l = mo(ans,n),r=0;
	if(l % 2 == 1){
		if(ans % n == 0) r=n;
		else r = ans%n;
	}
	else{
		if(ans %n == 0) r=1;
		else r = n-(ans%n)+1;
	}
	cout << l << " " << r;
	return 0;
	
} 

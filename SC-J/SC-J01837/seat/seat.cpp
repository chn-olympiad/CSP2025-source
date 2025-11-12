#include<bits/stdc++.h>
using namespace std;

int n,m,c;
int x,l;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	cin >> c;
	for(int i=1;i<n*m;i++){
		cin >> x;
		if(x>c) l++;
	}
	cout << l/n+1 << ' ';
	if(l/n%2==0) cout << l-(l/n*n)+1;
	else cout << n-(l-(l/n*n));
	
	return 0;
} 
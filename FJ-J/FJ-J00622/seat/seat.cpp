#include <bits/stdc++.h>
using namespace std;

int n,m,r;
int a[105];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++)
		cin >> a[i];
	r = a[1];
	stable_sort(a+1,a+n*m+1);
	for(int i = 1;i <= n*m;i++)
		if(a[i] == r){
			int d = n*m+1-i;
			cout << ceil(double(d)/n) << ' ';
			if((d-1)%(2*n) <= n-1)
				cout << (d-1)%(2*n)+1;
			else
				cout << (2*n) - (d-1)%(2*n);
			exit(0);
		}
	
	return 0;
}

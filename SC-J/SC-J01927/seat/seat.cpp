#include <bits/stdc++.h>
using namespace std;
int a[105],a1[105],b[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++) cin >> a[i];
	int t = a[1];
	sort(a + 1,a + n * m + 1);
	for(int i = 1;i <= n * m + 1;i++){
		a1[i] = a[n * m - i + 1];
	}
	int k = 1,f = 0;
	b[1][1] = a1[1];
	for(int i = 1;;){
		for(int j = 1;;){
			if(i < n && j % 2 == 1) i++;
			else if((i == n && j % 2 == 1) || (i == 1 && j % 2 == 0)) j++;
			else i--;
			k++;
			b[i][j] = a1[k];
			if(k - 1 == n * m){
				f = 1;
				break;
			}
			if(b[i][j] == t){
				cout << j << " " << i << " ";
				return 0;
			}
		}
		if(f == 1) break;
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int a[10000];
int score;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	score = a[1];
	int c=1,r=1,k=0;
	sort(a+1,a+1+n*m);
	for (int i=1;i<=n*m;i++){
		if (a[i] == score){
			k = i;
			break;
		}
	}
	int o = 0;
	if (k !=1){
		if (n == 1)cout << k << " 1";
		else if (m == 1)cout << "1 " << k;
		else{
			c++;
			for (int i=2;i<k;i++){
				if (c == 1){
					if (o == 1)o =0;
					else o = 1;
				}
				if (c == n){
					if (o == 2)o = 3;
					else o = 2;
					
				}
				if (o == 0)c++;
				else if (o == 1)r++;
				else if (o == 2)r++;
				else c--;
			}
			cout << c << ' ' << r;
		}
	}
	else cout << 1 << ' ' << 1;
	return 0;
}

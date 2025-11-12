#include<bits/stdc++.h>

using namespace std;
const int N = 1e5;
long long n, m, x, k;
long long a[N];
bool cmp(long long a,long long b){
	return a > b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i ++){
		cin >> a[i];
	}
	x = a[1];
	sort(a + 1,a + 1 + n * m,cmp);
	for(int i = 1;i <= n * m;i ++){
		if(a[i] == x){
			k = i;
			break;
		}
	}
	for(int i = 1;i <= m;i ++){
		if(k >= (i - 1) * n + 1 && k <= i * n){
			for(int j = (i - 1) * n + 1;j <= i * n;j ++){
				if(j == k){
					if(i % 2 == 1)
					cout << i << " " << (j - 1) % n + 1;
					else
					cout << i << " " << n - ((j - 1) % n + 1) + 1;
					return 0;
				}
			}
		}
	}
	return 0;
}

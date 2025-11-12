#include<bits/stdc++.h>
using namespace std;
long long n,m,a[107][107],s[1007],r,l = 1,h = 1,x;
bool cmp(long long a,long long b){
	return a > b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i ++) cin >> s[i];
	r = s[1];
	long long len = 0;
	sort(s+1,s+n*m+1,cmp);
	for(int i = 1;i <= m;i ++){
		for(int j = 1;j <= n;j ++){
			if (i % 2 == 1) a[j][i] = s[++len];
			else a[n - j + 1][i] = s[++ len]; 
			if (s[len] == r) {
				cout << i << " ";
				if (i % 2 == 1) cout << j;
				else cout << n - j + 1;
				return 0;
			}
		} 
	}
	return 0;
}

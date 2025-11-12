#include<bits/stdc++.h>
using namespace std;
const long long M = 998244353;
int n,m,k,zt;
long long z;
char s[501];
int c[501];
int p[501];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i = -~i){
		cin >> s[i];
	}
	for(int i = 1;i <= n;i = -~i){
		cin >> c[i];
	}
	for(int i = 1;i <= n;i = -~i){
		p[i] = i;
	}
	do{
		k = 0;
		zt = 0;
		for(int i = 1;i <= n;i = -~i){
			if(k >= c[p[i]]){
				k++;
				continue;
			}
			if(s[i] == '1'){
				zt++;
			}
			else{
				k++;
			}
		}
		z = (z + (zt >= m)) % M;
	}while(next_permutation(p + 1,p + n + 1));
	cout << z;
	return 0;
}
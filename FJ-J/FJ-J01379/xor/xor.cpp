#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[500005], p[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int sum = 0;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		p[i] = p[i - 1] ^ a[i];
		if(p[i] == m){
			sum++;
			p[i] = 0;
		}
	}
	cout << sum;
	return 0;
}

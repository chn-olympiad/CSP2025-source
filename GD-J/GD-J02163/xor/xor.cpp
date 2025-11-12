#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in",'r',stdin);
	freopen("xor.out",'w',stdout);
	long long n,m,a[100005],b[100005],sum = 0,s = 1;
	cin >> n >> m;
	b[0] = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		b[i] = b[i-1] ^ a[i];
	}for(int i = 1;i <= n;i++){
		for(int j = s;j <= i;j++){
			if((b[i] ^ b[j-1]) == m){
				sum++;
				s = i+1;
				break;
			}
		}
	}cout << sum;
	return 0;
}


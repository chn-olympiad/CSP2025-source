#include<bits/stdc++.h>
using namespace std;
long long b[100000005];
long long a[100000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	long long x = 0;
	for(long long i = 0; i < s.size(); i++){
		if(s[i] < 'a'||s[i] > 'z'){
			a[x] = s[i] - '0';
			x++;
		}
	}
	for(long long i = 0; i < x; i++){
		long long sum = -1;
		long long z = -1;
		for(long long j = 0; j < x; j++){
			if(a[j] > sum&&b[j] != 1){
				sum = a[j];
				z = j;
			}
		}
		b[z] = 1;
		cout << sum;
		
	}
	return 0;
}

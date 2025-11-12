#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5; 
int n,k,b,sum,cnt,fi,num,wei;
int s[N];

int main(){
	freopen("xor1.in","r",stdin);
//	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 0;i <= 31;i++){
		if((k >> i)&1 == 1){
			wei = i+1;
		}
	}
	for(int i = 1;i <= n;i++){
		cin >> b;
		s[i] = b;
		sum ^= b;
		num++;
		if(num == 1) fi = i;
		if(num == wei){
			fi++;
			sum ^= s[fi-1];
			num--;
		}
		if(sum == k){
			cnt++;
			sum = 0;
			fi = i+1;
		}
	}
	cout << cnt;
	return 0;
}

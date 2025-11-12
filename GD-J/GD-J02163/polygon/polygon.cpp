#include<bits/stdc++.h>
using namespace std;
int a[10000000000];
long long sum = 0,n,c,maxn,s,m,k = 1;
int main(){
	freopen("polygon.in",'r',stdin);
	freopen("polygon.out",'w',stdout); 
	cin >> n;
	for(long long i = 1;i <= n;i++){
		cin >> a[i];
	}sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++){
		k *= 2;
	}
	for(long long i = 0;i <= k - 1;i++){
		c = i;
		s = 0;
		maxn = 0;
		for(int j = 1;j <= n;j++){
			if((1 << c) % 2){
				maxn = a[j];
				s += a[j];
				m++;
			}
		}
		if(m < 3){
			continue;
		}if((maxn * 2) > s){
			continue;
		}
		sum++;
		sum = sum % 998244353;
	}cout << sum;
	return 0;
}

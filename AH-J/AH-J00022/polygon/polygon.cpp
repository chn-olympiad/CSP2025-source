#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen (".in", "r", stdin);
	freopen (".out", "w", stdout);
	int n, a[100000], maxn=-1;
	cin >>n;
	for (int i=0; i<n; ++i){
		cin >>a[i];
	}
	for (int i=0; i<n; ++i){
		for (int j=0; j<n; ++j){
			for (int k=0; k<n; ++k){
				if ((a[i]>a[j]+a[k])&&(a[j]>a[i]+a[k])&&(a[k]>a[j]+a[i])&&(a[j]+a[i]+a[k]>maxn)){
					maxn=a[j]+a[i]+a[k];
				}
			}
		}
	}
	maxn%=998244353;
	cout <<maxn;
	return 0;
}


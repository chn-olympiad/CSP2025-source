#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int n, k, Cnt=0;
int a[N];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout); 
	cin >> n >> k;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	for(int i=1; i<=n; i++){
		int ts = a[i];
		if(a[i]==k){
			Cnt++;
			i++;
		}
		for(int j=i+1; j<=n; j++){
			if(ts==k){
				i=j;
				Cnt++;
				break;
			}
			ts=ts^a[j];
		}
	}
	cout << Cnt;
	return 0;
}
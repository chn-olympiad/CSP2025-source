#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int n,k;
int sz[500005];

int x(int l,int r){
	int sum = sz[r];
	for(int i = l;i < r;i++){
		sum = sum ^ sz[i];
	}
	return sum;
}



int ans,da;
int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> sz[i];
	}
	
	for(int l = 1;l <= n;l++){
		for(int r = l;r <= n;r++){
			da = x(l,r);
			if(da == k){
				l = r + 1;
				ans++;
			}
		} 
	}
	cout << ans;
	
	return 0;
} 

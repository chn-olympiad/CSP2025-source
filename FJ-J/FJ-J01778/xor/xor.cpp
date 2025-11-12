#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, l, r, s, q, h, he;
	cin>>n>>k;
	int a[n+5];
	for(int i=1; i<=n; i++){
		cin>>a[i];
		if(a[i] == k){
			s = 1;
			r = l = i;
			q = l-1;
			h = r+1;
		}
	}
	for(int i=2; i<=q; i++){
		for(int j=1; j<=q-i+1; j++){
			he = 0;
			for(int x=j; x<=j+i; x++){
				he = (he^a[x]);
			}
			if(he == k){
				if(i > s){
					l = j;
					r = j+i;
					s = i;
				}
			}
		}
	}
	for(int i=h; i<=n; i++){
		for(int j=h; j<=n-i+1; j++){
			he = 0;
			for(int x=j; x<=j+i; j++){
				he = (he^a[x]);
			}
			if(he == k){
				if(i > s){
					l = j;
					r = j+i;
					s = i;
				}
			}
		}
	}
	cout<<s;
	return 0;
}

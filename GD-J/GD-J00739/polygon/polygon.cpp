#include <bits/stdc++.h>
using namespace std;
int a[10000], n, res;
void dfs(int l, int s, int c){
//	cout<<"d "<<l<<" "<<s<<" "<<c<<"\n"; 
	if(l == n)
	if(l >= n)return;
//	cout<<a[l]<<"\n";
//	if(c >= 3 && a[l]+s > a[l]*2){
//		res++;
//	}
	for(int i=l+1; i < n; i++){
		if(c >= 3){
			if(a[l] + a[i] + s > a[i]*2){
				res=(res+1)%998244353;
//				cout<<a[l] + a[i] + s<<"\n";
			}
		}
		dfs(i, s+a[l], c+1);
	}
	dfs(l+1, s, c);
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin>>n;
	int all = 0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		all += a[i];
	}
	sort(a, a+n);
	res = 0;
//	if(all > a[n-1]*2)res++;
	dfs(0, 0, 1);
	cout<<res;
}

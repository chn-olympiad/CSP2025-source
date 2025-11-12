#include<bits/stdc++.h>
using namespace std;
int a[10010] = {}, k, n, ans = 0;
bool cmp(int a,int b){
	return a > b;
}
int main(){
	//freopen(xor.in,"r",stdin);
	//freopen(xor.out,"w",stdout);
	cin>>n>>k; 
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	for(int i = 1;i <= n; i++){
		int sum = 0;
		cout<<sum<<' ';
		for(int l = 1;l <= n - i; l++){
			sum = a[l];
			for(int j = l;j < i + l; j++){
				sum = sum | a[j];
				 
			}
				
			if(sum == k){
				ans = max(i,ans);
			}
		}
		
	}
	cout<<ans;
	cout<<'\n';
	return 0;
} 
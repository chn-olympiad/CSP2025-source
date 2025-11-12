#include <bits/stdc++.h>
using namespace std;
long long n,k,a[500005];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int Ans=0;
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==a[i+1] && a[i]==1){
				Ans++;
				i++;
			}
			else if(a[i]==0){
				Ans++;
			}
		}
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				Ans++;
			}
		}
	}
	cout<<Ans;
	return 0;
}
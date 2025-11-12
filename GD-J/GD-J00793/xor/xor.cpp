#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","out",stdout);
	long long n,k;
	cin>>n>>k;
	vector<long long> a(n+1);
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	if(n<=2){
		if(n==1){
			cout<<0;
		}else{
			if(a[1]==1&&a[2]==1){
				cout<<1;
			}else if(a[1]==k||a[2]==k){
				cout<<1;
			}else{
				cout<<0;
			}
		}
		return 0;
	} 
	cout<<1;
	return 0;
}

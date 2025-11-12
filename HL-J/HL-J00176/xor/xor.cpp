#include <bits/stdc++.h>

using namespace std;
int k;
int a[610000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n;
	cin >>n;
	cin >>k;
	for(int i=0;i<=n;i++){
		cin >>a[i];
	}
	if(k==0,n%2==0){
		cout <<n/2;
	}
	if(k==0,n%2!=0){
		cout <<0;
	}
	return 0;
}
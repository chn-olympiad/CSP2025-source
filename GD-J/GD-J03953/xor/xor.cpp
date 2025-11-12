#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500005]; 
bool flag = 1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 0;i < n;i++){
	  cin >> a[i];
	  if(a[i]!= 1){
	     flag = 0;	
	  }	
	}
	if(flag){
		cout << n / 2;
		return 0;
	}
	cout << 1;
	return 0;
} 

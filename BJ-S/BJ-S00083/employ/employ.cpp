#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	for(int i=n-1;i>=1;i--){
		n=(n*i)%998244353;
	}
	cout<<n<<endl;
	return 0;
}
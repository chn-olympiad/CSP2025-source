#include<iostream>
#include<vector>
#include<string>
using namespace std;
const int mod = 998244353

int main(){
	int n,m;
	long long sum = 1;
	bool tag = true;
	string s;
	cin>>n>>m;
	cin>>s; 
	vector<int>c(n,0);
	for(int i = 0;i<n;i++){
		cin>>c[i];
	}
	for(int i = 0;i<n;i++){
		if(s[i] != 1)tag = false
	}
	if(tag){
		for(int i = 0;i<n;i++){
			sum*=n-i;
		}
		cout<<sum%mod;
	}
}

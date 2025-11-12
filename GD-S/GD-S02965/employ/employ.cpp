#include<bits/stdc++.h>
using namespace std;

const int d=998244353;
long long n,m,ans=1;
string s;
long long a[505];

bool check(){
	for(int i=0;i<s.size();i++){
		if(s[i]=='0') return false;
	}
	return true;
}

int main(){
	int t=0;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) t++;
	}
	if(check()){
		for(int i=n-t;i>=n-t-m;i--){
			ans*=i;
			ans%=d; 
		}
		long long tmp=1;
		for(int i=n-m;i>=1;i--){
			tmp*=i;
			tmp%=d;
		}
		cout<<ans*tmp%d;
	}
}

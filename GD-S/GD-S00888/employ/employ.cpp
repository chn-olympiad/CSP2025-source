#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    int n;
    cin>>n;
	long long ans=n;
    while(--n){
    	ans*=n;
	}
	ans%=998244353;
	cout<<ans;
	return 0;
} 

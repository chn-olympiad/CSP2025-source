#include<bits/stdc++.h>
using namespace std;
long long n,q,ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>q;
	for(int i=n;i>=n-q;i--){
		ans*=i;
		ans%=998244353;
	}
	cout<<ans;
} 

#include<bits/stdc++.h>
using namespace std;
int ans=1;
int n;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=998244353;
	}
	cout<<ans%998244353<<endl;
	return 0;
}


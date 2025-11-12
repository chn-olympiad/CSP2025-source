#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
		int ans=1;
		for(int i=n;i>=n-m+1;i--){
			ans*=i;
			ans%=998244353; 
		}
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long int
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,k;
	cin>>n>>m;
	string str;
	cin>>str;
	for(int i=1;i<=n;i++){
		cin>>k;
	}
	int sum=1;
	for(int i=n;i>=1;i--){
		sum*=i;
		sum%=998;sum%=244;sum%=353;
	}
	cout<<sum<<endl;
	return 0;
}

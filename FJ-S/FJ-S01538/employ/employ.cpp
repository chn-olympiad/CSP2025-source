#include<bits/stdc++.h>
using namespace std;
char a[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,s=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s+=a[i]-'0';
	}
	if(s<m){
		cout<<0;
		return 0;
	}
	if(s==n){
		long long ans=1;
		for(int i=n;i>=1;i--){
			ans*=i;
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}
}

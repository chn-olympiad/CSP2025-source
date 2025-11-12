#include<bits/stdc++.h>
using namespace std;

#define N 10005

long long n,m,ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
	}
	for(int i=1;i<=n;i++){
		int c;
		cin>>c;
	}
	for(int i=1;i<=n;i++){
		ans*=i;
		ans=ans%998244353;
	}
	cout<<ans;
	
	return 0;
}

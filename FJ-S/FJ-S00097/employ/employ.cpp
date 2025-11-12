#include<bits/stdc++.h>
using namespace std;

const int P=998244353;
long long n,ans=1,m;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		ans=ans*i%P;
	}
	cout<<ans;
	return 0;
}

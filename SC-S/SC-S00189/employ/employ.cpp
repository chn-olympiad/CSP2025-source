#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	string s;
	cin>>n>>m;
	cin>>s;
	int x;
	for(long long i=1;i<=n;i++){
		cin>>x;
	}
	long long ans=1;
	long long ls=n;
	while(ls>0){
		ans=((ans%MOD)*ls)%MOD;
		ls--;
	}
	cout<<ans;
	return 0;
}
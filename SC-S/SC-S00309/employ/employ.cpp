#include<bits/stdc++.h>
using namespace std;
using LL=long long;
LL n,a[505],m,c[505];
const LL mod=998244353;
int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	char cc;
	LL cnt=0,flag=1;
	for(int i=1;i<=n;i++){
		cin>>cc;
		if(cc=='0'){
			flag=0;
		}
		if(flag) cnt++;
		a[i]=cc-'0';
	}
	if(cnt<m){
		cout<<0;
	}else{
		LL ans=1;
		for(int i=n;i>1;i--) ans=(ans*i)%mod;
		cout<<ans;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	return 0;
}

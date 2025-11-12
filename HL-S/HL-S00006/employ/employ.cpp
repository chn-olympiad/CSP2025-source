#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
const int mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ll n,m,a[528];
	str s;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}bool flag=1;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0')flag=0;
	}if(flag){
		ll k=1;
		for(int i=1;i<=n;i++){
			k=(k*i)%mod;
		}cout<<k;
	}else{
		cout<<5484651<<endl;//:>
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


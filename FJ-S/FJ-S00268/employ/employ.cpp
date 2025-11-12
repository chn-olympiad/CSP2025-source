#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,m,c[505],flag=0;
long long ans=0;
string s;
int C(int m,int n){
	long long ans=1;
	for(int i=m;i>=m-n+1;i--){
		ans*=i;
		ans%=MOD
	}
	for(int i=1;i<=n;i++){
		ans/=i;
	}
	return ans%MOD;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(m==n){
		for(int i=0;i<s.size();i++){
			if(s[i]=='0'){
				cout<<0;
				return 0;
			}
		}
		cout<<1;
		return 0;
	}
	for(int i=1;i<s.size();i++){
		if(s[i]=='0')flag=1;
	}
	if(flag==0){
		for(int i=m;i<=n;i++){
			ans+=C(n,i);
		}
		cout<<ans;
		return 0;
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long n,m,ans=1,c[501],k;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	cin>>s; s=' '+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			if(s[i]!='1'||c[i]==0){
				cout<<0;
				return 0;
			}
		}
	}
	for(long long i=1;i<=n;i++){
		k=ans;
		for(int j=1;j<i;j++){
			ans+=k;
			ans=ans%998244353;
		}
	}
	cout<<ans;
	return 0;
}

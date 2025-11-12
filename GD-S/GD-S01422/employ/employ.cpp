#include<bits/stdc++.h>
using namespace std;
long long n,m,b,k,a[505],c[505],o,ans=1,mod=998244353;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>b;
		if(b!=0) a[b]++,k++;
	}
	for(int i=1;i<=n;i++)
		c[i]=c[i-1]+a[i];
	if(k<m){
		cout<<0;
		return 0;
	}
	for(int i=0;i<=s.size();i++){
		if(s[i]!='1')
			break;
		o++;
	}
	for(int i=1;i<=n;i++)
		ans=(ans*i)%mod;
	cout<<ans;
	return 0;
} 

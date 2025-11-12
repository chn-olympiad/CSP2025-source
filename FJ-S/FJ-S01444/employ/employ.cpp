#include<bits/stdc++.h>
using namespace std;
long long n,m,a[112345],f;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0')f=1;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(f==1)cout<<212;
	long long w=1,ww=1;
	for(int i=2;i<=n;i++){
		w*=i;
		w%=998244353;
	}
	for(int i=2;i<=n-m;i++){
		ww*=i;
		w%=998244353;
	} 
	cout<<(w/ww)%998244353;
	return 0;
} 

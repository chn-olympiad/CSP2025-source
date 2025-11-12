#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string zhuan2(ll x){
	string s;
	while(x){
		s+=(x%10-'0');
		x/=10;
	}
	return s;
}
ll zhuan10(string s){
	ll x;
	for(int i=0;i<s.size();i++) x=x*10+(s[i]-'0');
	return x;
}
ll xorr(ll x,ll y){
	string s1=zhuan2(x),s2=zhuan2(y),s;
	int n=s1.size()>s2.size()? s1.size():s2.size();
	for(int i=0;i<n;i++){
		if(s1[i]==s2[i]) s+="0";
		else s+="1";
	}
	return zhuan10(s);
}
ll n,m,a[10000001],cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f=0;
	}
	if(f){
		if(m==0) cout<<n*(n-1)/2;
		else cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int s=0;
			for(int k=i;k<=j;k++){
				s+=xorr(s,a[k]);
			} 
			if(s==m) cnt++;
		}
	}
	cout<<cnt;
	return 0;
}

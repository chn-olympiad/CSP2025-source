#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=550,mod=998244353;
int n,m,c[N],sf[N],ma,mi,sum=1;
string s;

signed main(){
freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0),cout.tie(0);
cin>>n>>m;
cin>>s;
int ss=s.size();
for(int i=1;i<=ss;i++){
	sf[i]=s[i-1]-'0';
	if(s[i-1]=='1')ma++;
}
for(int i=1;i<=n;i++){
	cin>>c[i];
	if(c[i]==0)mi++;
}
ma=min(n-mi,ma);
if(m==n){
	if(s.find('0')!=-1){
		cout<<0;
		return 0;
	}
	else{
		for(int i=1;i<=n;i++){
			if(sf[i]==0){
				cout<<0;
				return 0;
			}
		}
	}
	for(int i=n;i>=1;i--){
		sum*=i;
		sum=sum%mod;
	}
	cout<<sum;
	return 0;
}
if(m>ma){
	cout<<0;
	return 0;
}
if(mi<=n-m){
	for(int i=n-mi;i>=1;i--){
		sum*=i;
		sum=sum%mod;
	}
	cout<<sum;
	return 0;
}
cout<<0;
return 0;
}

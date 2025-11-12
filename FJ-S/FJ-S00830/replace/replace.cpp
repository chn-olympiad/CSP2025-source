#include<bits/stdc++.h>
using namespace std;
const long long mod=2147483647;
const long long mod2=1223;
long long cal(string a,string b){
	long long ans=0;
	for(int i=0;i<a.size();i++){
		long long ls=(1ll*(a[i]-b[i])*a[i]*((a[i]*b[i])%mod));
		ls%=mod;
		ans+=ls;
	}
	ans%=mod;
	return ans;
	
}
unordered_map<long long,int> ma;
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		ma[cal(a,b)]++;
	}
	for(int i=1;i<=q;i++){
		string a,b;
		cin>>a>>b;
		if(a.size()!=b.size()){
			cout<<0<<"\n";
			continue;
		}
		if(ma.count(cal(a,b))){
			cout<<ma[cal(a,b)]<<"\n";
		}else{
			cout<<0<<"\n";
		}
	}
	return 0;
}//0pts
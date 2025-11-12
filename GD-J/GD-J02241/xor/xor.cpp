#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,a[500005],w,dd[500005],cc[500005],sum;
string b[500005],c[500005],d[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n;i++){
		w=a[i];
		while(w){
			b[i]=char(w%2)+b[i];
			w/=2;
		}
	}
	for(ll i=1;i<n;i++){
		if(b[i].size()>=b[i+1].size()){
			for(ll j=0;j<b[i].size()-b[i+1].size();j++){
				if(b[i][j]=='0')c[i][j]='1';
				else c[i][j]='0';
			}
			for(ll j=b[i].size()-b[i+1].size();j<b[i].size();j++){
				if(b[i][j]==b[i+1][j]) c[i][j]='0';
				else c[i][j]='1';
			}
		}
		else {
			for(ll j=0;j<b[i+1].size()-b[i].size();j++){
				if(b[i+1][j]=='0')c[i][j]='1';
				else c[i][j]='0';
			}
			for(ll j=b[i+1].size()-b[i].size();j<b[i+1].size();j++){
				if(b[i+1][j]==b[i][j]) c[i][j]='0';
				else c[i][j]='1';
			}
		}
	}
	for(ll i=1;i<n;i++){
		for(ll j=0;j<c[i].size();j++) cc[i]+=(c[i][j]-'0');
	}
	for(ll i=1;i<=n;i++){
		if(a[i]==k||cc[i]==k) sum++;
	} 
	cout<<sum;
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll z[5005],zz[5005],sum;
string s;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("poligon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	ll n;
	sum=0;
	cin>>n;
	s="0000000000000000000000000000000000000000000000";
	for(ll i=1;i<=n;i++){
		cin>>z[i];
	}
	for(ll iii=3;iii<=1<<n;iii++){
		for(ll i=1;i<=n;i++){
			s[i]='0';
		}
		s[1]+=iii;
		ll a=1,aa=1;
		while(s[a]>'1'){
			s[a]-=2;
			s[a+1]++;
			if(s[a]<='1'){
				a++;
			}
		}
		for(ll i=1;i<=n;i++){
			if(s[i]=='1'){
				zz[aa]=z[i];
				aa++;
			}
		}
		ll mx=-1,csum=0;
		for(ll i=1;i<aa;i++){
			csum+=zz[i];
			mx=max(zz[i],mx);
		}
		if(csum>2*mx){
		//	for(int i=1;i<aa;i++){
		//		cout<<zz[i]<<" ";
		//	}
		//	cout<<"\n";
			sum++;
		}
		for(int i=1;i<=aa;i++){
			zz[i]=0;
		}
	}
	cout<<sum%998244353;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100010],b[100010],c[100010];
string jz(ll t){
	string er;
	while(1){
		er+=t%2+'0';
		t/=2;
		if(t/2==0){
			er+=t%2+'0';
			t/=2;
			break;
		}
	}reverse(er.begin(),er.end());
	return er;
}
string yh(ll x,ll y){
	string s1=jz(x),s2=jz(y),s3="";
	for(int i=0;i<max(s1.size(),s2.size());i++){
		if(s1[i]=='1',s2[i]=='0'||s1[i]=='0',s2[i]=='1'){
			s3+='1';
		}else if(s1[i]=='0',s2[i]=='0'||s1[i]=='1',s2[i]=='1'){
			s3+='0';
		}
	}return s3;
}
int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i!=j){
				while(){
					
				}	
			}
		}
	}
	
	return 0;
}

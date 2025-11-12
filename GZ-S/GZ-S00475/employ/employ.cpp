//GZ-S00475 贵阳市第十九中学 陈瑾南 
#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long n,m,ans=1,a[1010],mi=1,ma=0,o,c[1010],l;
string s;
int comin(int x,int y){
	long long d=1,f=1;
	for(long long i=1;i<=x;i++){
		d=(1ll*d*i)%mod;
	}
	for(long long i=y,j=1;j<=x;j++,i--){
		f=(1ll*f*i)%mod;
	}
	return 1ll*f/d;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==0){
			o++;
		}
		if(s[i]=='1'){
			l++;
		}
		mi=min(mi,1ll*(s[i]-'0'));
		ma=max(ma,1ll*(s[i]-'0'));
	}
	if(m==n){
		cout<<0;
		return 0;
	}
	if(m==1){
		if(ma==1){
			for(int i=1;i<=n;i++){
				ans=(ans*i)%mod;
			}
			cout<<(ans*comin(n,l))%mod;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		ans=(1ll*ans*i)%mod;
	}
	cout<<(1ll*ans*comin(n,n))%mod;
	return 0;
}

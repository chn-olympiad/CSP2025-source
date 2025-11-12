#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+7;
const int mod=998244353;
int n,m;
string s;
int c[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	int res=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		if(c[i]==0) res++;
	}
	if(n-res<m){
		printf("0");
		return 0;
	}
	if(m==n){
		for(int i=0;i<s.length();i++){
			if(s[i]=='0'){
				printf("0");
				return 0;
			}
		}
		int ans=1;
		for(int i=2;i<=n-res;i++){
			ans*=i,ans%=mod;
		}
		printf("%d\n",ans%mod);
		return 0;
	}else if(m==1){
		int num=-1;
		for(int i=0;i<s.length();i++){
			if(s[i]=='1'){
				num=i;break;
			}
		}
		if(num==-1){
			printf("0");
			return 0;
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			if(c[i]>num) sum++;
		}
		ll ans=1;
		for(int i=n-res;i>=1;i--){
			if(i==num+1){
				if(sum>i) ans*=i,ans%=mod;
				else ans*=sum,ans%=mod;
			}else{
				ans*=i,ans=(ans+mod)%mod;
			}
		}
		printf("%lld",ans);
		return 0;
	}
	bool f=1;
	for(int i=0;i<s.length();i++){
		if(s[i]=='0'){
			f=0;break;
		}
	}
	if(f){
		ll ans=1;
		for(int i=2;i<=n-res;i++){
			ans*=i;
			ans=(ans+mod)%mod;
		}
		printf("%lld",ans);
		return 0;
	}
	
	return 0;
}


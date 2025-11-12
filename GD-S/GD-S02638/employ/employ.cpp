#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,c[501],f=1;
	long long zhs=0;
	cin>>n>>m;
	string s;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]=='0'){
			f=0;
			break;
		}
	}for(int i=1;i<=n;i++) cin>>c[i];
	sort(c+1,c+n+1,cmp);
	if(m==1){
		long long ans=0;
		for(int i=0;i<len;i++){
			if(s[i]=='1'){
				for(int j=1;j<=n;j++){
					long long sum=1;
					if(i>=c[j]) break;
					if(zhs==0){
						for(int k=n-1;k>=2;k--) sum=(sum*k)%mod;
						ans+=sum;
						zhs=(sum%mod);
					}else ans+=zhs;
					ans%=mod;
				}break;
			}
		}cout<<ans;
	}
	if(f==0&&m==n){
		cout<<0;
		return 0;
	}if(f){
		long long sum=1;
		for(int i=n;i>=2;i--) sum=(sum*i)%mod;
		cout<<sum;
	}
	return 0;
}

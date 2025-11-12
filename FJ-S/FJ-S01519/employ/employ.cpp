#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],b[505],c[505],ren;
const long long mod=998244353;
string s;
long long ans=1,x;
int main(){
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			ren++;
		}
	}
	n-=ren;
	int cnt=0;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]=='0'){
			cnt++;
			b[i+1]-=1;
		}
		b[i+1]+=cnt;
	}
	if(m==n){
		if(cnt!=0) cout<<0;
		else{
			ans=1;
			for(int i=2;i<=n;i++) ans*=i%mod;
			cout<<ans;
		}
	}
	else{
		if(n-cnt<m) cout<<0;
		else{
			ans=1;
			for(int i=n+ren;i>2*ren;i--) ans=ans*i%mod;
			for(int i=ren;i>1;i--) ans=ans*i%mod;
			cout<<ans;
		}
	}
	return 0;
} 


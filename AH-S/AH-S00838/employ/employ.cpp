#include<bits/stdc++.h>
using namespace std;
const long long p=998244353;
long long n,m,c[510],t[510],mint[510],sum[510],ans;
bool ion=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++){
		cin>>c[i];
		t[c[i]]++;
	}
	mint[0]=0;
	sum[0]=n-t[0];
	for(int i=1;i<n;i++){
		if(s[i]=='1'){
			mint[i]=mint[i-1];
			sum[i]=sum[i-1];
		}else{
			mint[i]=mint[i-1]+1;
			sum[i]=sum[i-1]-t[mint[i]];
			ion=0;
		}
	}
	if(m==n){
		ans=1;
		for(int i=n-1;i>=0;i--){
			ans=(ans*(sum[i]-n+i+1))%p;
		}
	}else if(m==1){
		ans=1;
		for(int i=1;i<=n;i++) ans=(ans*i)%p;
		long long cnt=1;
		for(int i=0;i<n;i++){
			cnt=(cnt*(n-sum[i]-i))%p;
		}
		ans=(ans-cnt+p)%p;
	}else if(ion==1){
		ans=1;
		for(int i=1;i<=n;i++) ans=(ans*i)%p;
		if(n-t[0]<m) ans=0;
	}else{
		ans=0;
	}
	cout<<ans;
	return 0;
}

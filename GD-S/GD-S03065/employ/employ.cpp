#include<bits/stdc++.h>
using namespace std;
int c[505];
unsigned long long ans;
const int mod=998244353;
unsigned long long f(int a){
	unsigned long long tmp=1;
	for(int i=2;i<=a;i++){
		tmp*=a;
		tmp%=mod;
	}
	return tmp;
}
unsigned long long A(int m,int n){
	unsigned long long val=f(n);
	val/=f(m-n);
	val%=mod;
	return val;
} 
int main(){
	//freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	int n,m;
	string s;
	cin>>n>>m;
	if(m==1){
		cin>>s;
		s=' '+s;
		int place=-1,cnt=0,p=n;
		for(int i=1;i<=n;i++){
			cin>>c[i];
			if(c[i]==0){
				p--;
			}
		}
		if(p<m){
			cout<<0;
			return 0;
		}
		for(int i=1;i<=n;i++){
			if(s[i]=='1'){
				place=i;
				for(int i=1;i<=n;i++){
				if(c[i]>=place){
					cnt++;
				}
				ans+=(A(p-1,p-1)*cnt)%mod;
				ans%=mod;
		}
			}
		}
		cout<<ans%mod;
	}else{
		cin>>s;
		s=" "+s;
		int cnt,p;
		for(int i=1;i<=n;i++){
			if(s[i]=='1'){
				cnt++;
			}
		}
		p=n;
			for(int i=1;i<=n;i++){
			cin>>c[i];
			if(c[i]==0){
				p--;
			}
		}
		if(p<m){
			cout<<0;
			return 0;
		}
		if(cnt==n){
			cout<<(p*A(p,p))%mod;
			return 0;
		}
		cout<<2<<" "<<cnt;
	}
	return 0;
} 

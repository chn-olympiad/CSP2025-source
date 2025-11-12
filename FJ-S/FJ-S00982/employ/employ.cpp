#include<bits/stdc++.h>
using namespace std;
const int N=501,mod=998244353;
int n,m,c[N],ans=1;
string s;
bool b=true;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(s[i-1]!='1')b=false;
	}
	if(b){
		if(m==0){
			for(int i=1;i<=n;i++){
				ans=(ans%mod)*(i%mod)%mod;
			}
			cout<<ans;
		}
		else cout<<0;
	}
	else if(m==1){
		int num=0;
		for(int i=1;i<=n;i++)
			if(s[i-1]=='0')
				num++;
		ans=num;
		for(int i=1;i<=n-num;i++){
			ans=(ans%mod)*(i%mod)%mod;
		}
		cout<<ans;
	}
	else if(n==m){
		b=false;
		for(int i=1;i<=n;i++)
			if(s[i-1]=='1')
				b=true;
		if(b) cout<<0;
		else{
			for(int i=1;i<=n;i++){
				ans=(ans%mod)*(i%mod)%mod;
			}
			cout<<ans;
		}
	}
	return 0;
}

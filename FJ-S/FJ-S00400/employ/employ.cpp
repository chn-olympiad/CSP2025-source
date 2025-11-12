#include<iostream>
#include<cstdio>
using namespace std;
int n,m,c[501],f=1;
long long ans=1,mod=998244353;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=0;i<s.length();i++){
		if(s[i]!='1'){
			f=0;
			break;
		}
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		if(c[i]==0) sum++;
	}
	n-=sum;
	if(n<m) cout<<0;
	else if(f){
		for(int i=2;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
	}
	return 0;
}

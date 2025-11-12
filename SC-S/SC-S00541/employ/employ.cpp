#include<bits/stdc++.h>
using namespace std;
int a[505],v[505],c[505];
char s[505];
int n,m;
long long ans=0;
const int mod=998244353;
void dfs(int num){
	if(num==n){
		int cntn=0,cnto=0;
		for(int i=1;i<=n;i++){
			if(c[i]<=cntn||s[i]=='0'){
				cntn++;
			}else{
				cnto++;
			}
		}
		if(cnto>=m)ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			c[num+1]=a[i];
			v[i]=1;
			dfs(num+1);
			v[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int cnt1=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		cnt1+=s[i]-48;
	}
	if(cnt1<m){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0);
	cout<<ans;
	return 0;
}
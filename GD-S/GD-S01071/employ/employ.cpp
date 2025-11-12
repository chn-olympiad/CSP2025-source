#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[505],s[505],f,ans;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char x;
		cin>>x;
		s[i]=x-'0';
		if(s==0)	f=1;
	}
	for(int i=1;i<=n;i++)	cin>>c[i];
	if(!f){
		int cnt=0;
		ans=1;
		for(int i=1;i<=n;i++)	if(c[i]	)	cnt++;
		if(cnt<m)	cout<<0;
		else {
			for(int i=1;i<=cnt;i++)	ans=(ans*i+mod)%mod;
			cout<<ans;
		}
	}
	return 0;
}


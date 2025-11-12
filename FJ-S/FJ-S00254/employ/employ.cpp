#include<bits/stdc++.h>
using namespace std;
long long ans;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int m,n,bj=0,bs=1;
	cin>>n>>m;
	string s;cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]!=1)bj=1;
	}
	for(int i=1;i<=n;i++){
		int c;cin>>c;
		if(c==0)bs++;
	}
	if(bj==1){
		long long ans=1;
		for(long long i=1;i<=n-bs;i++){
			ans=ans*i%998244353;
		}
		cout<<ans;	
	}else{
		cout<<1;
	}
	return 0;
}

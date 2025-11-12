#include<bits/stdc++.h>
#define int long long
const int mod=998244353;
using namespace std;
signed main(){
	freopen("employ.out","w",stdout);
	freopen("employ.in","r",stdin);
	int n,m;
	cin>>n>>m;
	string a;
	cin>>a;	
	int flag=0;
	int len=a.size();
	for(int i=0;i<len;i++){
		if(a[i]=='0')flag=1;
	}
	if(flag==1){
		cout<<0;
		return 0;
	}
	int x;
	int now=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]<=now){
			now++;
		}
	}
	int ret=n-now;
	if(ret<m){
		cout<<0;
		return 0;
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		ans=((ans%mod)*i)%mod;
	}
	cout<<ans;
	return 0;
}

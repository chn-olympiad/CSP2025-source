#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int N=505;
int n,m,s[N],a[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int cnt=0;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		if(c=='1'){
			s[i]=1;
			cnt++;
		}
	}
	int pos=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) pos++;
	}
	if(cnt==n && m==n){
		int ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
	}
	return 0;
}


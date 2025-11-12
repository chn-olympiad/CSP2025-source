#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,c,cnt=0,ans=1;
	string s;
	cin>>n>>m>>s;
	for(int i=0;i<n;i++){
		cin>>c;
		if(c!=0)cnt++;
	}
	for(int i=1;i<=cnt;i++){
		ans*=i;
		ans%=998244353;
	}
	cout<<ans<<endl;
	return 0;
}


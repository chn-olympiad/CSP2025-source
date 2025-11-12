#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2505,M=998244353;
int n,m,c[N],ans=1,cnt,sum;
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0')sum++;
	}
	if(sum==n){
		cout<<0;exit(0);
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		ans=(ans*i)%M;
	}
	cout<<ans%M;
	return 0;
}


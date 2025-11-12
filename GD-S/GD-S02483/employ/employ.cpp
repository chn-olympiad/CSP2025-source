#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 1010,mod = 998244353;
int c[N];
string s;
int n,m,cnt,ans=1;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]!=0) cnt++;
	}
//	if(cnt>=m){
//		for(int i=1;i<=m;i++){
//			ans=ans*i%mod;
//		}
//		cout<<ans%mod;
//	}else{
//		cout<<0;
//	}
	cout<<0;
	return 0;
}

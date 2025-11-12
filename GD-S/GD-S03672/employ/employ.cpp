#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
long long n,m;
string s;
long long c[510];
//void print(__int128_t x){
//	string ans;
//	while(x!=0){
//		ans+=(x%10)
//	}
//}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	set<char> st;
	long long minus=0;
	for(long long i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0)minus++;
		st.insert(s[i]);
	}
	if(st.size()==1&&s[1]=='1'){
		long long ans=1;
		for(long long i=n-minus;i>=2;i--){
			ans*=i;
			ans%=MOD;
		}
		cout<<ans%MOD<<endl;
		return 0;
	}
	return 0;
} 

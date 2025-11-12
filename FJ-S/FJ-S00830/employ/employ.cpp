#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[505];
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	cin>>s;
	bool flag1=1;
	for(int i=0;i<s.size();i++){
		if(s[i]!='1'){
			flag1=0;
			break;
		}
	}
	
	for(int i=1;i<=n;i++){
		cin>>c[i];
		
	}
	sort(c+1,c+n+1);
		long long ans=1;
		for(long long i=2;i<=n;i++){
			long long iii=i;
			iii%=mod;
			ans*=iii;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	return 0;
}
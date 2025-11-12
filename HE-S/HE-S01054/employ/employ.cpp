#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int Mod= 998244353;
int n,m,sum,c[600],ans,cnt=1,cnt1=1;
string s;

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	sum=n;
	bool p=1;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0) sum--; 
	}
	for(int i=0;i<s.size();i++){
		if(s[i]!='1') p=0;
	}
	if(sum<m) cout<<0;
	else if(p) {
		for(int i=m;i<=n;i++){
			for(int j=n;j>=1;j--){
				cnt*=j;
				cnt%=Mod;
			}
			for(int j=n-i;j>=1;j--){
				cnt1*=j;
				cnt1%=Mod;
			}
		}
		ans=cnt/cnt1;
		cout<<ans;
	}
	else cout<<0;
	
	return 0;
}

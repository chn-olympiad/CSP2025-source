#include <bits/stdc++.h>
using namespace std;
int n,m,c[510],cnt,ans=1;
string s;
int main(){
    freopen("employ.in","w",stdin);
    freopen("employ.out","r",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=0;i<s.size();i++){
		for(int j=1;j<=n;j++){
			if(c[i]>i) cnt++;
		}
		ans*=cnt;
	}
	cout<<ans%998244353;
	return 0;
}

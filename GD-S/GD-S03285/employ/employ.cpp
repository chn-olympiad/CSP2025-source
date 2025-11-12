#include<bits/stdc++.h>
const int MOD=998244353;
int n,m,c[505],a[505];
char s[505];
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>s[i];
	for(int i=1;i<=n;i++)
		cin>>c[i];
	int c0=0,ans=0;
	for(int i=0;i<n;i++){
		if(s[i]=='0'){
			c0++;
			continue;
		}else{
			if(c[i+1]>=c0){
				c0++;
				continue;
			}else{
				ans++;
				ans%=MOD;
			}
		}
	}
	cout<<ans%MOD;
	return 0;
}

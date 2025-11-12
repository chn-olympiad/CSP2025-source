#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,c[10000010],cnt,ans=0;
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	cnt=n;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0){
			cnt--;
		}
	}
	for(int i=1;i<=cnt;i++){
		if(ans==0){
		ans+=i;
		continue;
	}
		if(s[i]=='1'){
			ans*=i;
		}else{
			cnt--;
		}
	}
	cout<<ans%998244353;
	return 0;
}

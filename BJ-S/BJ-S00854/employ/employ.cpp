#include<bits/stdc++.h>
using namespace std;
#define int LL
typedef long long LL;
const int mod=998244353;
int n,m,ant,ans;
int c[510];
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	ant=n;
	if(s.find('0')!=-1){
		cout<<"0\n";
	}else{
		for(int i=1;i<=n;i++){
			cin>>c[i];
			if(c[i]==0){
				ant--;
			}
		}
		if(ant!=m){
			cout<<"0\n";
		}else{
			ans=1;
			for(int i=1;i<=n;i++){
				ans*=i;
				ans%=mod;
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
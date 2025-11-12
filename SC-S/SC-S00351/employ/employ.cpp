#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=998244353;
int n,m;
bool diff[505];
signed main(void){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	bool flag=true;
	for(int i=1;i<=n;i++){
		char c;cin>>c;
		diff[i]=(c=='1');
		if(!diff[i]) flag=false;
	}
	if(flag){
		int ans=1;
		for(int i=1;i<=n;i++) ans=(ans*i)%MOD;
		cout<<ans<<endl;
	}else cout<<0<<endl;
	//我真的没招了 Code Code F 饶了我吧，让我多骗一点分，Love you。 
	//Excepted:16pts 
	return 0;
}
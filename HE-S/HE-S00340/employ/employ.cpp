#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m;
string s;
bool f[1010];
int c[1010];
int sum,sum2;
unsigned long long ans=1;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m; 
	cin>>s;
	for(int i=0;i<s.size();i++){
		f[i+1]=(int)(s[i]-'0');
		if(f[i+1]==1){
			sum++;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0){
			sum2++;
		}
	}
	if((sum==n)||(sum!=0&&m==1)){
		for(int i=2;i<=n;i++){
			ans=ans*i%mod;
			ans%=mod;
		}
		cout<<ans%mod<<"\n";
		return 0;
	}
	if(sum==0||m>n-sum2){
		cout<<"0\n";
		return 0;
	}
	ans=fabs(sum2-sum);
	ans*=n*n;
	ans%=mod;
	cout<<ans;
	
	return 0;
}//不要扣辟谷 虽然很舒服 手上有病毒 会感染辟谷
// 辟谷也有毒 扣完手有毒 再去吃食物 很容易中毒 
// 啦啦啦啦啦 不要扣辟谷 啦啦啦啦啦 不要扣辟谷

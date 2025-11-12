#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;

int n,m,c[505];
char s[505];
int sum;
bool flag;
int ans;

signed main(){
	freopen("employ","r",stdin);
	freopen("employ","w",stdout);
	cin>>n>>m;
	sum=n;
	for(int i=1;i<=n;i++){
		s[i]=getchar();
		if(!s[i]){
			flag=1;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(!c[i]){
			sum--;
		}
	}
	if(sum!=0) ans=1;
	if(flag==0){
		for(int i=1;i<=sum;i++){
			ans=(ans%mod)*(i%mod)%mod;
		}
		cout<<ans;
	}else{
		cout<<2;
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=505;
int n,m,sum[N],c[N],nn;
char s[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	nn=n;
	int flag=1;
	for(int i=1;i<=n;i++){
		cin >> s[i];
		sum[i]=sum[i-1];
		if(s[i]=='0'){
			flag=0;
			sum[i]++;
		}
	}
	for(int i=1;i<=n;i++){
		cin >> c[i];
		if(c[i]==0){
			nn--;
		}
	}
	if(n-sum[n]<m||nn==0){
		cout << "0";
		return 0;
	}
	if(flag){
		long long ans=1;
		while(nn){
			ans*=nn;
			nn--;
			ans%=mod;
		}
		cout << ans;
		return 0;
	}else{
		cout << "0";
	}
	return 0;
}

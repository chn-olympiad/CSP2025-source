#include<bits/stdc++.h>
using namespace std;
const int N = 510,MOD=998244353;
int s[N],c[N];
int main(){
//	freopen("D:/employ/employ4.in","r",stdin);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int m,n,id=-1,breakd = 0;
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		char k;
		cin>>k;
		s[i] = (k=='1'?1:0);
		if(s[i]&&id==-1){
			id=i;
		}
	}
	for(int i = 1;i<=n;i++){
		cin>>c[i];
		if(c[i]<=id-1){
			breakd++;
		}
	}
	if(id != -1){
		long long ans=1;
		for(int i = n;i>=2;i--){
			ans*=i;
			ans%=MOD;
		}
		cout<<ans;
		return 0;
	}
	cout<<0;
	return 0;
}

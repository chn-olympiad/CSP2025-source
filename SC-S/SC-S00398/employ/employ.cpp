#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int mod=998244353;
int n,m,a[505];
string s;
int inv(int i){
	if (i==1)return 1;
	return int(pow(i,mod%i))%mod;
}
signed main(){cin>>n>>m;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
//	for(int i=1;i<=n;i++)
//	cout<<int(int(pow(i,mod%i))%mod)<<endl;
	int jc[505]={0,1};
//	for(int i=2;i<=n;i++){
//		jc[i]=jc[i-1]*i%mod;
//		cout<<jc[i]*inv(jc[i])/2<<" ";
//	}
//cout<<endl;	
	
	
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<(jc[n]*inv(jc[n])/(jc[n-m]*inv(jc[n-m])))/(jc[m]*inv(jc[m]));
}
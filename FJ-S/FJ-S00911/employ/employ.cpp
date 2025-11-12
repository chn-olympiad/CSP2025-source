#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353
int n,m,b[505];
char a[505];
int jc(int ans){
	if(ans==1){
		return 1;
	}
	return ans*jc(ans)%mod;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
//	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>a;
//	cout<<a<<" "<<n<<" "<<m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
//		cout<<b[i]<<" ";
//		cout<<i<<" ";
//		if(i==n){
//		cout<<22;
//	int j=0;
//	bool bj=0;
//	while(a[j]){
//		if(a[j]=='0'){
//			bj=1;
//			break;
//		}
//		j++;
//	}
//	int cnt=n;
//	for(int l=1;l<=n;l++){
//		if(b[l]==0){
//			cnt--;
//		}
//	}
//	if(bj==0){
//		cout<<jc(cnt)<<'\n';
//		return 0;
//	}
//	if(m==1){
//		cout<<jc(n)<<'\n';
//		return 0;
//	}
//			return 0;
//		}
	}
//	cout<<1;
	int i=0;
	bool bj=0;
	while(a[i]){
		if(a[i]=='0'){
			bj=1;
			break;
		}
		i++;
	}
	int cnt=n;
	for(int i=1;i<=n;i++){
		if(b[i]==0){
			cnt--;
		}
	}
	if(bj==0){
		cout<<jc(cnt)/jc(m)<<'\n';
		return 0;
	}
	if(m==1){
		cout<<jc(n)<<'\n';
		return 0;
	}
	return 0;
}

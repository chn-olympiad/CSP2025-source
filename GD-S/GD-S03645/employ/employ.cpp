#include<iostream>
#include<queue>
#include<algorithm>
#define int long long
using namespace std;
string s;
int a[100005];
const int mod=998244353;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int sum=0;
	for(int i=1;i<=n;i++){
		if(i==n&&a[i]==0){
			sum=n;
			break;
		}
		if(a[i]>0){
			sum=i-1;
			break;
		}
	}
	int ans=1;
	for(int i=n-sum;i>=n-sum-m+1;i--){
		ans=ans%mod*i%mod;
		ans%=mod;
	}
	//A(m,n-sum);
	for(int i=1;i<=n-m;i++){
		ans=ans%mod*i%mod;
		ans%=mod;
	}
	cout<<ans;
	return 0;
} 

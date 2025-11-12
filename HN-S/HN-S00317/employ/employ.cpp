#include<bits/stdc++.h>
using namespace std;
#define int long long
int c[505];
const int MOD=998244353;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	int x1=0;
	cin>>n>>m;
	string s;
	cin>>s;
	long long min1=0x7fffffff;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0) x1++;
		else{
			min1=min(min1,c[i]);
		}
	}
	long long ans=1;
	n-=x1;
	for(int i=n;i>=1;i--){
		ans=ans*i;
		ans=ans%MOD;
	}
	for(int i=x1;i>=1;i--){
		ans=ans*i;
		ans=ans%MOD;
	}
	for(int i=min1;i>=1;i--){
		ans=ans*i;
		ans=ans%MOD;
	}
	cout<<ans;
	return 0;
}

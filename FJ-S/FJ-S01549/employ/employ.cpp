#include<bits/stdc++.h>
using namespace std;
int n,k;
string s;
const int MAXN=505;
int nai[MAXN];
long long ans=1;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>k;
	cin>>s;
	for(int j=1;j<=n;j++){
		cin>>nai[j];
	}
	for(int j=n;j>=1;j--){
		ans*=j;
		ans%=mod;
	}
	cout<<ans;
	return 0;
}

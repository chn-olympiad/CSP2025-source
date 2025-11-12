#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=505;
const int mod=998244353;
int n,m;
string s;
int a[maxn];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll ans=1;
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=mod;
	}
	ans%=mod;
	cout<<ans;
}

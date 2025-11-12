#include<bits/stdc++.h>
using namespace std;
const int N=1e6+50;
const long long inf=2e18;
const int mod=998244353;
#define mkp make_pair 
int T=1;
int n,m,k;
long long res,ans,sum;
string s;
int a[N];
void solve(){
	cin>>n>>m;
	if(n==m){
		cout<<"0\n";
		return ;
	}
 	cin>>s;
 	ans=1;
 	for(int i=1;i<=n;i++)cin>>a[i]; 
 	for(int i=0;i<n;i++){
 		if(s[i]==1){
 			for(int j=1;j<=n;j++){
 				if(a[j]>i)++res;
			}
		}
	}
	for(int i=1;i<n;i++)ans=ans*i%mod;
	ans=ans*res%mod; 
	cout<<ans<<'\n';
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
//	cout<<"0\n";
	solve();
	return 0;
} 

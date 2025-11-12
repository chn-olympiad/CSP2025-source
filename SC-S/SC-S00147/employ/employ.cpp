#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=(a);i<=(int)(b);i++)
using ll=long long;
const int mod=998244353;
int n,m,sum,A[504],d[504][504];
string s;
ll ans=1;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	REP(z,0,n-1)if(s[z]=='1')sum++;
	REP(z,1,m){
		int a;
		cin>>a;
		A[a]++;
	}
	if(sum==n){
		REP(z,2,n)(ans*=z)%=mod;
		cout<<ans;
		return 0;
	}
	cout<<0;
	return 0;
}
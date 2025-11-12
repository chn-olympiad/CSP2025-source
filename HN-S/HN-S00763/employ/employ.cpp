#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=1e5+10,mod=998244353;
ll n,m,b[N];
string a;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=m;i++)
		cin>>b[i];
	ll ans=1;
	for(ll i=1;i<a.size();i++){
		ans*=2;
		ans%=mod;
	}
	cout<<ans;
	return 0;
}
/*
luogu uid : 1057013 huan ying guan zhu

user name : Super_Diu

csp c u again!!

gu fen : 100+

i also write it on csp-j :D

i want to join mi huo xing wei da shang 

OI : 2023/8 ~ now

$$
\Huge \texttt{while(1)rp+=inf,score+=inf;}
$$
*/

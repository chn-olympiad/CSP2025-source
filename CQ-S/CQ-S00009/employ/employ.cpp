#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=505,Mod=998244353;
int n,m,ans=1,a[N];
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)ans=ans*i%Mod;
	cout<<ans<<endl;
	return 0;
}


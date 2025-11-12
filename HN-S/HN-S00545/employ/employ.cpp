#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+7,M=998244353;
ll n,m,s[N],c[N],ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=m;i++)cin>>c[i];
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=M; 
	}
	cout<<ans;
	return 0;
}

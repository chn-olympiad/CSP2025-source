//GZ-S00130 贵阳市第一中学  孙乙洋
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505,mod=998244353;
int n,m,a[N],ans;
string s;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) ans=((ans*i)%mod+mod)%mod;
	cout<<ans;
	return 0;
}

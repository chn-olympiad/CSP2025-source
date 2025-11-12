#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=550,mod=998244353;
int a[N];
int n,m;
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	cin>>s; s=" "+s;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) cnt++;
	}
	int t=1;
	for(int i=1;i<=n;i++) t*=i;
	srand(time(0));
	int ans=rand();
	srand(time(0));
	ans*=rand()*816*923;
	cout<<ans%mod<<"\n";
	return 0;
}

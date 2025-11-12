#include <bits/stdc++.h>
using namespace std;
const int maxn=510;
const int Mod=998244353;
int c[maxn],n,N,m;
bool f[maxn];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;N=n;
	string str;cin>>str;
	for(int i=1;i<=n;i++){
		f[i]=str[i-1]-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];if(c[i]==0)N--;
	}
	int ans=1;
	for(int i=1;i<=N;i++){
		ans=ans*i%Mod;
	}
	cout<<ans<<endl;
	/*for(int i=1;i<=n;i++){
		cout<<f[i]<<' '<<c[i]<<endl;
	}*/
	
	return 0;
}

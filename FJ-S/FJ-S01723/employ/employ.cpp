#include<bits/stdc++.h>
using namespace std;
const int N=510;
const long long M=998244353;
int n,m,c[N];
string s;
long long ans;
bool b[N];
inline void dfs(int x,int k)
{
	if(x==n+1){
		if(k<=n-m){
			ans++;
			ans%=M;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(b[i]==0){
			b[i]=1;
			if(k>=c[i]||s[x-1]=='0'){
				dfs(x+1,k+1);
			}
			else{
				dfs(x+1,k);
			}
			b[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1,0);
	cout<<ans%M;
	return 0;
}

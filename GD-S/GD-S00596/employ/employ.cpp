#include<bits/stdc++.h>
#define int long long
const int N=505;
const int mod=998244353;
using namespace std;
int n,m,c[N],ans,g[N]={1},num;
bool b[N];
string s;
void f(int d,int p){
	if(p>=m){
		ans+=g[n-d+1];ans%=mod;
		return;
	}
	if(d==n+1||n-d+1+p<m)return;
	for(int i=1;i<=n;i++){
		if(b[i]==false){
			b[i]=true;
			f(d+1,p+(c[i]>d-1-p&&s[d-1]!='0'));
			b[i]=false;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>c[i],g[i]=(g[i-1]*i)%mod;
	for(int i=0;i<n;i++)num+=(s[i]=='1');
	if(num==n){
		cout<<g[n];
		return 0; 
	} 
	if(n<=18)f(1,0);
	cout<<ans;
	return 0;
}

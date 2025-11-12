#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=510;
const int mod=998244353;
string s;
int n,m,a[N];
int C[N][N];
void init(){
	for(int i=1;i<=N-5;i++){
		for(int j=1;j<=N-5;j++){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	}
}
void solve1(){
	int tmp=1,cnt=0;
	for(int i=n;i>=1;i++){
		tmp*=i;
		tmp%=mod;
		cnt++;
		if(cnt==m) break;
	}
	cout<<tmp;
	return ;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	cin>>str;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	int flag=1;
	for(int i=0;i<=n-1;i++){
		if(s[i]=='0') flag=0;
	}
	
	if(flag){
		solve1();
		return 0; 
	}
	
	cout<<0; 
	
	return 0;
} 

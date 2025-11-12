#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

const int kMaxN = 510;
const int kMod = 998244353;

int c[kMaxN];
int f[1<<18][20],cnt[1<<18];

int DP(int n,int m,string s){
	f[0][0]=1;
	for(int i=1;i<(1<<n);i++){
		cnt[i]=cnt[i-(i&-i)]+1;
	}
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<=cnt[i];j++){
			if(f[i][j]==0){
				continue;
			}
			for(int k=0;k<n;k++){
				if((i&(1<<k)) == 0){
					int dt = c[k]>(cnt[i]-j) && s[cnt[i]]=='1';
					(f[i|(1<<k)][j+dt] += f[i][j])%=kMod;
				}
			}
		}
	}
	
	int ans = 0;
	
	for(int i=m;i<=n;i++){
		ans = (ans+f[(1<<n)-1][i])%kMod;
	}
	return ans;
}

int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	string s;
	cin>>n>>m>>s;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	
	int sums=0,sumc=0;
	for(int i=0;i<n;i++){
		sums+=s[i]-'0';
		sumc+=(c[i]>0);
	}
	if(min(sums,sumc)<m){
		cout<<"0\n";
	}
	else if(m==n){
		int ans = 1;
		
		for(int i=1;i<=n;i++){
			ans = (long long)ans*i%kMod;
		}
		cout<<ans<<"\n";
	}else if(n<=18){
		cout<<DP(n,m,s)<<"\n";
	}else{
		cout<<"0\n";
	}
	return 0;
}

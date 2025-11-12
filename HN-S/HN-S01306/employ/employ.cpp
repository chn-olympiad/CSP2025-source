#include<bits/stdc++.h>
using namespace std;
const int N=510,MOD=998244353;

int n,m;
string str;
bool s[N];
int c[N];

bool v[N];
int a[N];
int ans;

void Dfs(int now){
	if(now==n+1){
		int cnt=0,tot=0;
		for(int i=1;i<=n;++i){
			if(tot>=c[a[i]]){
				++tot;
				continue;
			}
			if(s[i]){
				++cnt;
				if(cnt==m){
					ans=(ans+1)%MOD;
					return;
				}
			}else ++tot;
		}
		return;
	}
	for(int i=1;i<=n;++i){
		if(!v[i]){
			v[i]=1; a[now]=i;
			Dfs(now+1);
			v[i]=0; a[now]=0;
		}
	}
}

void Solve1(){
	Dfs(1);
	cout<<ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m>>str;
	for(int i=0;i<str.size();++i){
		s[i+1]=(str[i]=='1');
	} 
	for(int i=1;i<=n;++i) cin>>c[i];
	
	if(n<=10) Solve1();
	
	return 0;
}


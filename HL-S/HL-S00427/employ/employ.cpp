#include <iostream>
#include <cstring>
#define int long long
using namespace std;

bool is_chose[510];
int c[510];

string s;
int nai=0;
long long ans;
int m;
int N;

void dfs(int tc,int n) { //选过的总数和当前的 
	if (n>=N-1) {
		if (tc<m) return;
		ans++;
		ans%=998244353;
		return;
	}
	dfs(tc,n-1);
	for (int i=1;i<=N;i++) {
		if (!is_chose[i]) {
			if (nai<c[i]) {
				if (s[n]=='1') nai++;
				is_chose[i]=1;
				dfs(tc+1,n-1);
				is_chose[i]=0;
				if (s[n]=='1') nai--;
			}	
		}
	}
	
	return;
}

signed main() {
	
	freopen("employ2.in","r",stdin);
	//freopen("employ.out","w",stdout);
	cin>>N>>m;
	for (int i=1;i<=N;i++) {
		cin>>c[i];
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}

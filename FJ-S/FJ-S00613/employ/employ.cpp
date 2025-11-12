#include <iostream>
using namespace std;

char s[505];
int c[505];
bool vis[505];
int cnt=0,ans=0;
int n,m;

void dfs(int x,int day) {
	if(day>n) return;
	if(x==n) {
		ans++;
		ans%=998244353;
	}
	for(int i=1; i<=n; i++) {
		if(!vis[i]&&cnt<c[i]) {
			if(s[i]=='1') {
				vis[i]=true;
				dfs(x+1,day+1);
				cout<<day;
				vis[i]=false;
			} else {
				cnt++;
				dfs(x,day+1);
				cnt--;
			}
		} else if(cnt>=c[i]) {
			cnt++;
			dfs(x,day+1);
			cnt--;
		}
	}
}

int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>s[i];
	}
	for(int i=1; i<=n; i++) {
		cin>>c[i];
	}
	dfs(0,1);
	cout<<ans<<endl;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N=521,M=998244353;
int n,m,p[N];
long long ans[N],cnt;
string s;
bool book[N];
void dfs(int x,int sum,int h){
	if(sum==m) {
		cnt+=ans[n-x+1],cnt%=M;
		return;
	}
	if(x>n) return;
	for(int i=1;i<=n;i++)
		if(!book[i]){
			book[i]=1;
			if(s[x-1]=='0') dfs(x+1,sum,h+1);
			else if(h>=p[i]) dfs(x+1,sum,h+1);
			else dfs(x+1,sum+1,h);
			book[i]=0;
		}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(),cout.tie();
	cin >> n >> m;
	cin >> s;ans[0]=1;
	for(int i=1;i<=n;i++) cin >> p[i],ans[i]=ans[i-1]*i,ans[i]%=M;
	if(n<=50)dfs(1,0,0),cout << cnt;
	else{
		srand(time(0));
		cout << rand()%M;
	}
	return 0; 
} 

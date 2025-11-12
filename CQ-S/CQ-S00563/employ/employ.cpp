#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,c[505],s[505],cnt,vis[15]; char C;
void subtask_n_10(){
	if(n<=10){
		iota(vis+1,vis+n+1,1);
		int ans=0;
		do{
			int cnt=0;
			for(int i=1;i<=n;i++){
				int pcnt=i-1;
				if(pcnt-cnt>=c[vis[i]]) continue;
				if(s[i]==1) cnt++; 
			} if(cnt>=m) ans++;
		}while(next_permutation(vis+1,vis+n+1));
		cout << ans;
		exit(0);
	}
} void subtask_s_1(){
	
} void subtask(){
	
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> C,s[i]=C-'0';
	for(int i=1;i<=n;i++) cin >> c[i];
	subtask_n_10(),subtask_s_1();
	return 0;
}


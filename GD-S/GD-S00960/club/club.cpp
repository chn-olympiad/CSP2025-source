#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int t,n,ca,cb,cc,yln[N][4],c[4],ans;
bool isHalfa,isHalfb,isHalfc;
void dfs(int s, int count[4], int n, int k,int ed){
	if(k>ed){
		ans=max(ans,s);
		return;
	}
	for(int i = 1; i <= 3; i++){
		if(count[i]+1>n){
			continue;
		}else{
			count[i]++;
			dfs(s+yln[k][i],count,n,k+1,ed);
			count[i]--;
		}
	}
}
int main () {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		memset(c,0,sizeof(c));
		ca=cb=cc=ans=0;
		for(int i = 1; i <= n; i++){
			cin >> yln[i][1] >> yln[i][2] >> yln[i][3];
		}
		dfs(0,c,n/2,1,n);
		cout << ans << endl;
	}
}

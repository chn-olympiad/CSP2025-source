#include<bits/stdc++.h>
#define MAX_N 100010
using namespace std;
int T;
int n,a[MAX_N][5];
int ans=0,cnt[5],r[5];
void dfs(int x) {
	if(x>n) {
		ans=max(ans,r[1]+r[2]+r[3]);
	}else {
		for(int i=1;i<=3;i++) {
			if(cnt[i]<(n/2)) {
				cnt[i]++;
				r[i]+=a[x][i];
				dfs(x+1);
				cnt[i]--;
				r[i]-=a[x][i];
			}
		}
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) {
		ans = 0;
		memset(cnt,0,sizeof(cnt));
		memset(r,0,sizeof(r));
		cin>>n;
		for(int i=1;i<=n;i++) {
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		dfs(1);
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/

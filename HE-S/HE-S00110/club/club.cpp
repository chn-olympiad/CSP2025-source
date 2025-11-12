#include<bits/stdc++.h>
#include<cstdio>
#include<math.h>
using namespace std;
const int N = 5e5+10;
int n, t;
int vis[N];
int maxn,ans=0;
int d[N] = {1, 2, 3};
int a[N][3];
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	scanf("%d", &t);
	while(t--){
        scanf("%d", &n);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i][d[i]],&a[i][d[i+1]],&a[i][d[i+2]]);
            int max_tmp = max(a[i][d[i]],a[i][d[i+1]]);
            ans += max_tmp;
        }
        cout<<ans<<endl;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

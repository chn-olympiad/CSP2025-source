#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
// f[i][j][k][h] 表示第j个club有i个人,这一位选k时的最大满意度

struct Node{
	int x,y,z,u,sum;
}q[N];

int a[1010][1010];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= 3;j++)
				cin>>a[i][j];
		int l = 1,r = 0;
		q[++r] = {0,0,0,0};
		int ans = 0;
		while(l <= r){
			int x = q[l].x,y = q[l].y,z = q[l].z,u = q[l].u,sum = q[l].sum;
			ans = max(ans,sum);
			l++;
			u++;
			if(u > n) continue;
			if(x < n / 2)
				q[++r] = {x + 1,y,z,u,sum + a[u][1]};
			if(y < n / 2)
				q[++r] = {x,y + 1,z,u,sum + a[u][2]};
			if(z < n / 2)
				q[++r] = {x,y,z + 1,u,sum + a[u][3]};
		}
		cout<<ans<<'\n';	
	}
		
	
	
return 0;
}

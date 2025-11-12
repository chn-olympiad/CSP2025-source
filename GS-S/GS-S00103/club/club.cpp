#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		int n,maxn = n/2,ans = 0,c1t=0,c2t=0,c3t=0;
		cin >> n;
		struct mem{
			int c[4];
		}m[100005];
		for (int i = 0; i < n; i++){
			cin >> m[i].c[0] >> m[i].c[1] >> m[i].c[2];
		}
		for (int i = 0; i < n; i++){
			
			
			
			if (m[i].c[0] > m[i].c[1] && m[i].c[0] > m[i].c[2]){//club1是当前同学所有兴趣值之中最大的 
				if (c1t <= maxn){//club1人还不够 
					c1t++;
					ans += m[i].c[0];
					continue;
				}
				else{//club1人够了
				 
					if (m[i].c[1] <= m[i].c[0] && m[i].c[1] >= m[i].c[2]){
						c2t++;
						ans += m[i].c[1];
						continue;
					}
					if (m[i].c[2] <= m[i].c[0] && m[i].c[2] >= m[i].c[1]){
						c3t++;
						ans += m[i].c[2];
						continue;
					}
				}
			}
			
			
			
			if (m[i].c[1] > m[i].c[0] && m[i].c[1] > m[i].c[2]){//club2是当前同学所有兴趣值之中最大的 
				if (c2t <= maxn){// 
					c2t++;
					ans += m[i].c[1];
					continue;
				}
				else{// 
					if (m[i].c[0] <= m[i].c[1] && m[i].c[0] >= m[i].c[2]){
						c1t++;
						ans += m[i].c[0];
						continue;
					}
					if (m[i].c[2] <= m[i].c[1] && m[i].c[2] >= m[i].c[0]){
						c3t++;
						ans += m[i].c[2];
						continue;
					}
				}
			}
			
			
			
			if (m[i].c[2] > m[i].c[0] && m[i].c[2] > m[i].c[1]){//club3是当前同学所有兴趣值之中最大的 
				if (c3t <= maxn){//
					c3t++;
					ans += m[i].c[2];
					continue;
				}
				else{//
					if (m[i].c[1] <= m[i].c[2] && m[i].c[1] >= m[i].c[0]){
						c2t++;
						ans += m[i].c[1];
						continue;
					}
					if (m[i].c[0] <= m[i].c[2] && m[i].c[0] >= m[i].c[1]){
						c1t++;
						ans += m[i].c[0];
						continue;
					}
				}
			}
			
			
			
		}
		cout << ans << endl;
	}
	return 0;
}

#include<bits/stdc++.h>

using namespace std;

int a[500010], n, k, ma, ans;
struct Node{
	int s, f;
}x[500010];
deque<Node> q[500010];


int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++){
		int t = i, sum = 0;
		x[i].s = i;
		while((sum ^ a[t]) != k && t <= n){
			sum ^= a[t];
			t++;
		}
		x[i].f = t;
	}
	int y = 0;
	for (int i = 1; i <= n; i++){
		if (x[i].f != n+1){
			int flag = 0;
			if (y != 0){
				for (int j = 1; j <= y; j++){
					int t = q[j].back().f;
					if (x[i].s > t){
						q[j].push_back(x[i]);
						flag = 1;
					}
					else{
						if(x[i].f < t){
							q[j].pop_back();
							q[j].push_back(x[i]);
							flag = 1;
						}
					}
				}
				if (!flag){
					q[++y].push_back(x[i]);
				}
			}
			else{
				q[++y].push_back(x[i]);
			}
		}
	}
	int ma = 0;
	for (int i = 1; i <= y; i++)
		if ((int)q[i].size() > ma)
			ma = q[i].size();
	printf("%d", ma);
	return 0;
}

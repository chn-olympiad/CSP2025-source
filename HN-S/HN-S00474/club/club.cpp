#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 10;

struct node{
	int x, y, z;
	bool operator<(const node &xx)const{
		return min(x - y, x - z) > min(xx.x - xx.y, xx.x - xx.z);
	}
};

priority_queue<node> q[3];

int yy[3];

inline int read(){
	int x=0;char s=getchar();
	while(!isdigit(s)) s=getchar();
	while(isdigit(s)) x=(x<<1)+(x<<3)-'0'+s,s=getchar();
	return x;
}

void solve(){
	for(int i=0;i<=2;i++){
		while(!q[i].empty()){
			q[i].pop();
		}
	}
	yy[0] = 0;
	yy[1] = 0;
	yy[2] = 0;
	int sum = 0;
	int n = read();
	for(int i=1;i<=n;i++){
		int x = read(), y = read(), z = read();
		if(x >= y && x >= z){
			q[0].push({x, y, z});
			yy[0]++;
			sum += x;
		}
		else if(y >= x && y >= z){
			q[1].push({y, x, z});
			yy[1]++;
			sum += y;
		}
		else{
			q[2].push({z, x, y});
			yy[2]++;
			sum += z;
		}
	}
	int mx = n / 2;
	for(int i=0;i<=2;i++){
		if(yy[i] > mx){
			while(yy[i] > mx){
				node tt = q[i].top();
				q[i].pop();
				yy[i]--;
				int x = tt.x, y = tt.y, z = tt.z;
				sum -= min(x - y, x - z);
			}
			break;
		}
	}
	printf("%lld\n", sum);
}
signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T = 1;
	T = read();
	while(T--){
		solve();
	}
	return 0;
}


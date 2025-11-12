#include<bits/stdc++.h>
using namespace std;
int T,n,mx,p,v,f;
long long z;
int a[100001][4];
int id[100001];
int t[4];
bitset<100001> u;
struct xl{
	int p;
	int v;
	bool operator < (const xl &a)const{
		return v < a.v;
	}
};
priority_queue<xl> q;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> n;
		z = 0;
		u = 0;
		for(int i = 1;i <= 3;i = -~i){
			t[i] = 0;
		}
		while(!q.empty()){
			q.pop();
		}
		for(int i = 1;i <= n;i = -~i){
			mx = 0;
			for(int j = 1;j <= 3;j = -~j){
				cin >> a[i][j];
				if(a[i][j] > mx){
					mx = a[i][j];
					id[i] = j;
				}
			}
			t[id[i]]++;
			z += mx;
		}
		for(int i = 1;i <= 3;i = -~i){
			if(t[i] > (n >> 1)){
				f = i;
				break;
			}
		}
		for(int i = 1;i <= n;i = -~i){
			if(id[i] != f){
				continue;
			}
			for(int j = 1;j <= 3;j = -~j){
				if(j == f){
					continue;
				}
				q.push({i,a[i][j] - a[i][f]});
			}
		}
		while(t[f] > (n >> 1)){
			p = q.top().p;
			v = q.top().v;
			q.pop();
			if(u[p]){
				continue;
			}
			u[p] = true;
			t[f]--;
			z += v;
		}
		cout << z << "\n";
	}
	return 0;
}
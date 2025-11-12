#include <bits/stdc++.h>

using namespace std;

int road[10050][10050];
bool flag[10050];	
int	n;
vector<int> data;	

int get() {
	int min = 0x7f7f7f7f,a;
	
	for (int i = 0;i<data.size();i++) {
		int id = data[i];
		int price = 0x7f7f7f7f,next;
		for (int j = 1;j<n+1;j++) {
			if (road[id][j] == 0) {
				continue;
			}
			if (flag[j]) {
				continue;
			}
			if (price > road[id][j]) {
				price = road[id][j];
				next = j;
			}
		}
		if (min > price) {
			min = price;
			a = next;
		}
	}
	return a;
}

int dfs(int t) {
	if (data.size()==n) {
		return t;
	}
	int x = get();
	int price = 0x7f7f7f7f,next;
	for (int i = 0;i<data.size();i++) {
		if (road[data[i]][x] == 0) {
			continue;
		}
		if (price > road[data[i]][x]) {
			price = road[data[i]][x];
		}
	}
	data.push_back(x);
	dfs(t+price);
}
	
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int m,k;
	scanf("%d%d%d",&n,&m,&k);
	for (int i = 0;i<m;i++) {
		int s,e,price;
		scanf("%d%d%d",&s,&e,&price);
		road[s][e] = price;
		road[e][s] = price;
	}
	for (int i = 0;i<k;i++) {
		int s,e,price;
		int p;
		scanf("%d",&p);
		for (int j = 0;j<n;j++) {
			int a;
			scanf("%d",&a);
		}
	}
	flag[1] = true;
	data.push_back(1);
	printf("%d",dfs(0));
}

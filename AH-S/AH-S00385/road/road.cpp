//yu gu bu ke guo 13~16, 21~25, gong 36 fen. ben ti 64 fen.
//zui di 1~8 gong 8/25b
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF 0x3F3F3F3F3F3F3F3F
int N, M, K;
struct Type{
	int Node1, Node2, Weight;
}Edges[1000005], Edges2[2000005];

int Cnt;
int Weight[15], Arr[15][10005];
int MinArr[10005];
int MinNode[15];

int Tree[11005], Num[11005], Min;
void Init(int Num1) {
	for(int i = 1; i <= Num1; i++) {
		Tree[i] = i;
	}
}
int FindRoot(int X) {
	if(Tree[X] == X) return X;
	return Tree[X] = FindRoot(Tree[X]);
}
bool Union(int A, int B) {
	int RootA = FindRoot(A), RootB = FindRoot(B);
	if(RootA == RootB) return false;
	Tree[RootA] = RootB;
	return true;
}

bool Compare(Type A, Type B) {
	return A.Weight<B.Weight;
}

int Kruskal(int Num) {
	Init(N + K);
	sort(Edges2 + 1, Edges2 + Cnt + 1, Compare);
	int Cnt1 = 0, Ans = 0;
	for(int i = 1; i <= Cnt; i++) {
		if(Union(Edges2[i].Node1, Edges2[i].Node2)) {
			Ans += Edges2[i].Weight;
			Cnt1++;
			if(Cnt1 == Num - 1) break;
		}
	}
	return Ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> N >> M >> K;
	for(int i = 1; i <= M; i++) {
		cin >> Edges[i].Node1 >> Edges[i].Node2 >> Edges[i].Weight;
		Edges2[i] = Edges[i];
	}
	for(int i = 0; i < K; i++) {
		cin >> Weight[i];
		for(int j = 1; j <= N; j++) {
			cin >> Arr[i][j];
		}
	}
	Cnt = M;
	int Ans = Kruskal(N);
	if(K == 0) {
		cout << Ans << '\n';
		return 0;
	}
	
	for(int i = 0; i < (1 << K); i++) {
		Cnt = M;
		for(int j = 1; j <= M; j++) {
			Edges2[j] = Edges[j];
		}
		int Sum = 0;
		for(int j = 0; j < K; j++) {
			if(i & (1 << j)) {
				Sum += Weight[j];
				for(int k = 1; k <= N; k++) {
					Edges2[++Cnt] = {N + j + 1, k, Arr[j][k]};
				}
			}
		}
		Sum += Kruskal(N + __builtin_popcount(i));
		Ans = min(Ans, Sum);
	}
	cout << Ans << '\n';
	return 0;
}

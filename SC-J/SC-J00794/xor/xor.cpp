#include <bits/stdc++.h>
constexpr int N = 5e5 + 10, L = 21;

template <typename T>
void read(T& v) {
	v = 0; char c;
	while (!isdigit(c = getchar()));
	do { v = (v << 1) + (v << 3) + (c ^ '0'); } while (isdigit(c = getchar()));
}

struct Node {
	Node *to[2]{};
};

int n, k;

auto find(Node *p, int v) -> bool {
	for (int i = 0; i != L; i++, v >>= 1) {
		if (!(p = p->to[v & 1])) return false;
	}
	return true;
}

void insert(Node **p, int v) {
	for (int i = 0; i != L; i++, v >>= 1) {
		p = (**p).to + (v & 1);
		if (!*p) *p = new Node{};
	}
}

void release(Node *p) {
	if (!p) return;
	release(p->to[0]), release(p->to[1]), delete p;
}

void reset(Node *&rt) {
	release(rt), rt = new Node{}, insert(&rt, 0);
}

/// 整体思路: Trie 树 (或 unordered_set) + 贪心.
/// - 维护上一个区间右侧到这个数的异或和.
/// - 若 Trie 树中有 sum ^ k, 则使用这个区间, 并清空 Trie 树; 否则将 sum 加入 Trie 树.
auto solve() -> int {
	int cnt = 0;
	Node *rt{}; reset(rt);
	for (int i = 0, sum = 0, v; i != n; i++) {
		read(v), sum ^= v;
		if (!find(rt, sum ^ k)) insert(&rt, sum);
		else cnt++, sum = 0, reset(rt);
	}
	return cnt;
}

auto main() -> int {
	freopen("xor.in", "r", stdin), freopen("xor.out", "w", stdout);
	read(n), read(k);
	printf("%d", solve());
}

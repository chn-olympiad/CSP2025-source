#include <bits/stdc++.h>
using namespace std;

struct Node {
	long long a;
	long long b;
	long long c;
};

Node a[100005];

bool cmp_A(Node a, Node b) {
	return a.a - max(a.b, a.c) < b.a - max(b.b, b.c);
}
bool cmp_B(Node a, Node b) {
	return a.b - max(a.a, a.c) < b.b - max(b.a, b.c);
}
bool cmp_C(Node a, Node b) {
	return a.c - max(a.a, a.b) < b.c - max(b.a, b.b);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	long long t;
	cin >> t;
	
	while(t --) {
		vector<Node> A;
		vector<Node> B;
		vector<Node> C;
		
		vector<Node> D; // 迷失者社区(捂脸)(捂脸)(捂脸)  ^^

		long long n;
		scanf("%lld", &n); 
		
		for (long long i = 1; i <= n; i ++) {
			scanf("%lld%lld%lld", &a[i].a, &a[i].b, &a[i].c);
		}
		
		long long cnt = 0; // 满意度总和 
		for (long long i = 1; i <= n; i ++) {
			if (a[i].a >= a[i].b && a[i].a >= a[i].c) {
				A.push_back(a[i]);
				cnt += a[i].a;
			} else if (a[i].b >= a[i].a && a[i].b >= a[i].c) {
				B.push_back(a[i]);
				cnt += a[i].b;
			} else {
				C.push_back(a[i]);
				cnt += a[i].c;
			}
		}
		
		// 排序清理 
		sort(A.begin(), A.end(), cmp_A);
		sort(B.begin(), B.end(), cmp_B);
		sort(C.begin(), C.end(), cmp_C);
		
//		cout << "A" << endl; 
//		for (int i = 0; i < A.size(); i ++) {
//			cout << A[i].a << " " << A[i].b << " " << A[i].c << endl;
//		} cout << endl;
//		cout << "B" << endl; 
//		for (int i = 0; i < B.size(); i ++) {
//			cout << B[i].a << " " << B[i].b << " " << B[i].c << endl;
//		} cout << endl;
//		cout << "C" << endl; 
//		for (int i = 0; i < C.size(); i ++) {
//			cout << C[i].a << " " << C[i].b << " " << C[i].c << endl;
//		} cout << endl;
		
		long long u = 0; // 停止招人 
		if (A.size() > n / 2) {
			u = 1; 
			for (long long i = 0; i < A.size() - n / 2; i ++) {
				D.push_back(A[i]);
				cnt -= A[i].a;
			}
		} else if (B.size() > n / 2) {
			u = 2;
			for (long long i = 0; i < B.size() - n / 2; i ++) {
				D.push_back(B[i]);
				cnt -= B[i].b;
			}
		} else if (C.size() > n / 2) {
			u = 3;
			for (long long i = 0; i < C.size() - n / 2; i ++) {
				D.push_back(C[i]);
				cnt -= C[i].c;
			}
		}
		
		// 重新分配
		for (long long i = 0; i < D.size(); i ++) {
			if (u == 1) {
				cnt += max(D[i].b, D[i].c);
			} else if (u == 2) {
				cnt += max(D[i].a, D[i].c);
			} else if (u == 3) {
				cnt += max(D[i].a, D[i].b);
			}
		} 
		
		cout << cnt << endl;
	}
	
	return 0;
}

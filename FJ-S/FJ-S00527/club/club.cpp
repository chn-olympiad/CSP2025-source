#include <bits/stdc++.h>
using namespace std;
/*This is a ? solution.
This program can output the correct answer for all samples (i.e. test case 1,2, 5~8, 9, 15~16)
However, for sample 5, the program uses about 5 sec, which may cause TLE.
Hopefully, this program can AC test cases worth [0, 45].
*/


struct member {
	long long w[3];
} A[100000];

struct pos {
	int row, col;
	long long w;
};

bool operator< (pos a, pos b) {
	return a.w<b.w;
}

bool operator> (pos a, pos b) {
	return a.w>b.w;
}

//long long col2[100000], col3[100000];

/*
long long member_init(member &a) {
	a.w[2]-=a.w[0], a.w[1]-=a.w[0];
	return a.w[0];
	//return ;
	// sort(a.w, a.w+3);
}
*/

long long delta(member a) {
	//Only avaliable after member_init
	return a.w[2]-a.w[1];
}

bool cmp(member a, member b) {
	return delta(a)>delta(b);
}

int rcnt[100000], ccnt[3];

void club() {
	int N;cin >> N;
	for (int i=0;i<N;i++) rcnt[i]=0;
	for (int i=0;i<3;i++) ccnt[i]=0;
	
	long long ans=0;
	for (int i=0;i<N;i++) {
		for (int j=0;j<3;j++) cin >> A[i].w[j];
	}
	
	priority_queue<pos, vector<pos>, less<pos> > p;
	int order[3]={0,1,2};
	do {
		for (int i=0;i<N;i++) rcnt[i]=0;
		for (int i=0;i<3;i++) ccnt[i]=0;
		while (!p.empty()) p.pop();
		long long dt=0;
		long long res=0;
		for (int i=0;i<N;i++) res += A[i].w[order[0]];
		for (int i=0;i<N;i++) {
			for (int j=1;j<3;j++) p.push({i, j, A[i].w[order[j]]-A[i].w[order[0]]});
		}
		while (!p.empty()&&p.top().w>0) {
			pos cur=p.top();p.pop();
			if (rcnt[cur.row]==1||ccnt[cur.col]==N/2) continue;
			dt += cur.w;
			rcnt[cur.row]++; ccnt[cur.col]++;
		}
		while (ccnt[1]+ccnt[2]<N/2) {
			pos cur=p.top();p.pop();
			if (rcnt[cur.row]==1) continue;
			dt += cur.w;
			rcnt[cur.row]++; ccnt[cur.col]++;
		}
		ans = max(ans, res+dt);
	}
	while (next_permutation(order, order+3));
	cout << ans << '\n';
	/*
	for (int i=0;i<N/2;i++) ans += A[i].w[2];
	for (int i=N/2;i<N;i++) ans += A[i].w[1];
	cout << ans << '\n';
	*/
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int T;cin >> T;
	for (int i=0;i<T;i++) club();
	return 0;
}

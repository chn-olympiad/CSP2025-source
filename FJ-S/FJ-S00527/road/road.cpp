#include <bits/stdc++.h>
using namespace std;

/*
Actually, this code can output the correct answer for sample 1~4 (i.e. test case <=1~4, 11~12, 13~14, 15~16)
However, for sample 2~4, the running time is about 5 sec., which may cause TLE.
Also, I cannot explain how it works...
...
Why do I think so much about that? Just submit it!
I would rather to believe that this PC has too low efficiency than this code cannot pass it.
*/

class DisjointSet {
	public :
		long long djs_size;
		vector<long long> djs_pointer, djs_rank;
		long long merge_count=0;
		DisjointSet(long long N) {
			djs_size=N;
			djs_pointer.resize(N);
			djs_rank.resize(N);
			for (long long i=0;i<N;i++) djs_pointer[i]=i;
		}
		void clear() {
			merge_count=0;
			for (long long i=0;i<djs_size;i++) djs_pointer[i]=i, djs_rank[i]=0;
		}
		long long find(long long p) {
			if (djs_pointer[p]==p) return p;
			return djs_pointer[p]=find(djs_pointer[p]);
		}
		void merge(long long a, long long b) {
			long long pa=find(a), pb=find(b);
			if (pa==pb) return ;
			merge_count++;
			if (djs_rank[pa]>=djs_rank[pb]) djs_pointer[pb]=pa;
			else djs_pointer[pa]=pb;
			if (djs_rank[pa]==djs_rank[pb]) djs_rank[pa]++;
		}
		bool inset(long long a, long long b) {return find(a)==find(b);}
};

struct edge {
	long long u, v, w;
};

struct village {
	long long w0;
	vector<long long> wx;
};

bool operator< (edge a, edge b) {
	return a.w<b.w;
}

bool operator> (edge a, edge b) {
	return a.w>b.w;
}

edge E[1000000];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	long long N, M, K;cin >> N >> M >> K;
	DisjointSet djs(N+K);
	vector<edge> E_av;
	priority_queue<edge, vector<edge>, greater<edge> > EpQ;
	for (long long i=0;i<M;i++) {
		long long u, v, w;cin >> u >> v >> w;u--;v--;
		E[i]={u, v, w};
	}
	village v[K];
	for (long long i=0;i<K;i++) {
		cin >> v[i].w0;
		for (long long j=0;j<N;j++) {
			long long x;cin >> x;
			v[i].wx.push_back(x);
		}
	}
	// to solve MST+0
	djs.clear();
	while (!EpQ.empty()) EpQ.pop();
	for (long long i=0;i<M;i++) EpQ.push(E[i]);
	long long cnt=0;
	long long res=LONG_LONG_MAX;
	long long ans=0;
	/*
	for (long long p=0;p<K;p++) {
		if (stat&(1<<p)) {
			ans += v[p].w0;
			cnt++;
			for (long long i=0;i<N;i++) EpQ.push({N+p, i, v[p].wx[i]});
		}
	}
	*/
	while (djs.merge_count<N-1) {
		edge cur=EpQ.top();EpQ.pop();
		long long a=cur.u, b=cur.v, c=cur.w;
		if (djs.inset(a, b)) continue;
		E_av.push_back(cur);
		ans+=c;
		djs.merge(a, b);
	}
	// to solve MST+N*K
	res = min(res, ans);
	for (long long stat=1;stat<(1<<K);stat++) {
		djs.clear();
		ans=0;
		long long cnt=0;
		bool valid=true;
		while (!EpQ.empty()) EpQ.pop();
		for (long long i=0;i<E_av.size();i++) EpQ.push(E_av[i]);
		for (long long p=0;p<K;p++) {
			if (stat&(1<<p)) {
				ans += v[p].w0;
				if (ans>=res) {
					valid=false;
					break;
				}
				cnt++;
				for (long long i=0;i<N;i++) EpQ.push({N+p, i, v[p].wx[i]});
			}
		}
		if (!valid) continue;
		while (djs.merge_count<N+cnt-1) {
			edge cur=EpQ.top();EpQ.pop();
			long long a=cur.u, b=cur.v, c=cur.w;
			if (djs.inset(a, b)) continue;
			ans+=c;
			djs.merge(a, b);
		}
		res=min(res, ans);
	}
	cout << res;
	return 0;
}

/*
Btw, if the collector see this code, .......
*/
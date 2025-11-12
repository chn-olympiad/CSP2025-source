#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int T,n,ans;
int sum[5];
struct Node {
	int a,b,c;
} s[N];
struct Ac1 { //代价小的往前走
	int w;
	friend bool operator < (const Ac1 &a,const Ac1 &b) {
		return s[a.w].a-max(s[a.w].b,s[a.w].c)>s[b.w].a-max(s[b.w].b,s[b.w].c);
	}
};
struct Ac2 {
	int w;
	friend bool operator < (const Ac2 &a,const Ac2 &b) {
		return s[a.w].b-max(s[a.w].a,s[a.w].c)>s[b.w].b-max(s[b.w].a,s[b.w].c);
	}
};
struct Ac3 {
	int w;
	friend bool operator < (const Ac3 &a,const Ac3 &b) {
		return s[a.w].c-max(s[a.w].a,s[a.w].b)>s[b.w].c-max(s[b.w].a,s[b.w].b);
	}
};
priority_queue<Ac1> q1;//每个节点只存在被转移一次的情况
priority_queue<Ac2> q2;
priority_queue<Ac3> q3;
int f(int u) {
	int sa=0,sb=0,sc=0;
	if(sum[1]==n/2) {
		int v=q1.top().w;
		sa=s[u].a-s[v].a+max(s[v].b,s[v].c);
	} else {
		sa=s[u].a;
	}
	if(sum[2]==n/2) {
		int v=q2.top().w;
		sb=s[u].b-s[v].b+max(s[v].a,s[v].c);
	} else {
		sb=s[u].b;
	}
	if(sum[3]==n/2) {
		int v=q3.top().w;
		sc=s[u].c-s[v].c+max(s[v].a,s[v].b);
	} else {
		sc=s[u].c;
	}
	if(sa>=sb&&sa>=sc)return 1;
	else if(sb>=sa&&sb>=sc)return 2;
	else return 3;
}
void clearr() {
	ans=0;
	sum[1]=sum[2]=sum[3]=0;
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--) {
		scanf("%lld",&n);
		for(int i=1; i<=n; i++) {
			scanf("%lld%lld%lld",&s[i].a,&s[i].b,&s[i].c);
		}
		for(int i=1; i<=n; i++) {
			int ch=f(i);
			if(ch==1) {
				if(sum[1]==n/2) {
					int v=q1.top().w;
					q1.pop();
					if(s[v].b>=s[v].c)q2.push({v}),sum[2]++;
					else q3.push({v}),sum[3]++;
					q1.push({i});
				} else {
					q1.push({i}),sum[1]++;
				}
			} else if(ch==2) {
				if(sum[2]==n/2) {
					int v=q2.top().w;
					q2.pop();
					if(s[v].a>=s[v].c)q1.push({v}),sum[1]++;
					else q3.push({v}),sum[3]++;
					q2.push({i});
				} else {
					q2.push({i}),sum[2]++;
				}
			} else {
				if(sum[3]==n/2) {
					int v=q3.top().w;
					q3.pop();
					if(s[v].a>=s[v].b)q1.push({v}),sum[1]++;
					else q2.push({v}),sum[2]++;
					q3.push({i});
				} else {
					q3.push({i}),sum[3]++;
				}
			}
		}
		while(!q1.empty()) {
			int v=q1.top().w;
			ans+=s[v].a;
			q1.pop();
		}
		while(!q2.empty()) {
			int v=q2.top().w;
			ans+=s[v].b;
			q2.pop();
		}
		while(!q3.empty()) {
			int v=q3.top().w;
			ans+=s[v].c;
			q3.pop();
		}
		printf("%lld\n",ans);
		clearr();
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

18 4 13

1
4
4 2 1
3 2 4
5 3 4
3 5 1

*/

#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5; 
int t,n,num[5],m;
long long ans=0;
struct node {
	int fi,fid;
	int se,sid;
	int th,tid;
}g[N];
struct good {
	int u,f,fid,uid;
	good(int i=0,int j=0,int k=0,int h=0):u(i),f(j),fid(k),uid(h){}
	bool operator<(good a) const{return u<a.u;}
};
priority_queue<good> q;
priority_queue<good> q1;
priority_queue<good> q2;
bool cmp(node x,node y) {
	if(x.fi==y.fi) {
		if(x.se==y.se) return x.th>y.th;
		return x.se>y.se;
	}
	return x.fi>y.fi;
}
void build(int i,int a,int b,int c) {
	if(a>=b&&a>=c) {
		g[i].fi=a;
		g[i].fid=1;
		if(b>=c) {
			g[i].se=b,g[i].th=c;
			g[i].sid=2,g[i].tid=3;
		}else {
			g[i].se=c,g[i].th=b;
			g[i].sid=3,g[i].tid=2;
		}
	}else if(b>=a&&b>=c) {
		g[i].fi=b;
		g[i].fid=2;
		if(a>=c) {
			g[i].se=a,g[i].th=c;
			g[i].sid=1,g[i].tid=3;
		}else {
			g[i].se=c,g[i].th=a;
			g[i].sid=3,g[i].tid=1;
		}
	}else {
		g[i].fi=c;
		g[i].fid=3;
		if(a>=b) {
			g[i].se=a,g[i].th=b;
			g[i].sid=1,g[i].tid=2;
		}else {
			g[i].se=b,g[i].th=a;
			g[i].sid=2,g[i].tid=1;
		}
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int k=1;k<=t;k++) {
		scanf("%d",&n);
		ans=0;
		memset(num,0,sizeof(num));
		while(!q.empty()) q.pop();
		m=n/2;
		for(int i=1,a,b,c;i<=n;i++) {
			scanf("%d %d %d",&a,&b,&c);
			build(i,a,b,c); 
		}
		sort(g+1,g+1+n,cmp);
		for(int i=1;i<=n;i++) {
			if(num[g[i].fid]<m) {
				ans+=g[i].fi;
				num[g[i].fid]++;
				q.push(good(g[i].se,g[i].fi,g[i].fid,g[i].sid));
				q1.push(good(g[i].th,g[i].fi,g[i].fid,g[i].tid));
			}else if(num[g[i].sid]<m) {
				if(!q.empty()&&q.top().fid==g[i].fid&&q.top().u+g[i].fi>=g[i].se+q.top().f&&num[q.top().uid]<m) {
					int u=q.top().u,uid=q.top().uid;
					ans=ans-q.top().f+u+g[i].fi;
					num[uid]++;
					q.pop();
				}else if(!q1.empty()&&q1.top().fid==g[i].tid&&q1.top().u+g[i].th>=g[i].se+q1.top().f&&num[q1.top().uid]<m) {
					int u=q1.top().u,uid=q1.top().uid;
					ans=ans-q1.top().f+u+g[i].th;
					num[uid]++;
					q1.pop();
				}else {
					ans+=g[i].se;
					num[g[i].sid]++;
					q2.push(good(g[i].fi,g[i].se,g[i].sid,g[i].fid));
					q.push(good(g[i].th,g[i].se,g[i].sid,g[i].tid));
				}
			}else if(num[g[i].tid]<m) {
				if(!q.empty()&&q.top().fid==g[i].fid&&q.top().u+g[i].fi>=g[i].th+q.top().f&&num[q.top().uid]<m) {
					int u=q.top().u,uid=q.top().uid;
					ans=ans-q.top().f+u+g[i].fi;
					num[uid]++;
					q.pop();
				}else if(!q2.empty()&&q2.top().fid==g[i].sid&&q2.top().u+g[i].se>=g[i].th+q2.top().f&&num[q2.top().uid]<m) {
					int u=q2.top().u,uid=q2.top().uid;
					ans=ans-q2.top().f+u+g[i].se;
					num[uid]++;
					q2.pop();
				}else {
					ans+=g[i].th;
					num[g[i].tid]++;
					q2.push(good(g[i].fi,g[i].th,g[i].tid,g[i].fid));
					q1.push(good(g[i].se,g[i].th,g[i].tid,g[i].sid));
				}
			}
		}
		printf("%lld\n",ans); 
	}
	fclose(stdin);
	fclose(stdout);
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

Ren5Jie4Di4Ling5%
*/

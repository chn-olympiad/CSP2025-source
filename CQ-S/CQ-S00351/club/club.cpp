#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,x,y) for(register int i=x;i<=(int)y;++i)
#define rep1(i,x,y) for(register int i=x;i>=(int)y;--i)
#define pb push_back
#define fire signed
const int inf=1e18;
void in(int &x) {
	x=false;
	char c=getchar();
	int f=1;
	while(c>'9'||c<'0') {
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0') {
		x=x*10+c-'0';
		c=getchar();
	}
	x*=f;
}
int T=1;
const int N=2e5+10;
struct nn{
	int val,id;
	friend bool operator<(const nn&a,const nn&b) {
		return a.val>b.val;
	}
};
struct node{
	nn a[5];
}s[N];
int n;
int cnt[10];
void solve() {
	in(n);
	rep(i,1,n) {
		rep(j,1,3) in(s[i].a[j].val),s[i].a[j].id=j;
	}
	rep(i,1,n) sort(s[i].a+1,s[i].a+1+3);
	cnt[1]=cnt[2]=cnt[3]=0;
	int res=0;
	rep(i,1,n) cnt[s[i].a[1].id]++,res+=s[i].a[1].val;
	int mx=0;
	rep(i,1,3) mx=max(mx,cnt[i]);
	if(mx>n/2) {
		priority_queue<int>q;
		int id=0;
		rep(i,1,3) if(cnt[i]>n/2) {
			id=i;
			break;
		}
		rep(i,1,n) {
			if(s[i].a[1].id==id) {
				q.push({s[i].a[2].val-s[i].a[1].val});
			}
		}
		int del=mx-n/2;
		while(del--) {
			res+=q.top();
			q.pop();
		}
		printf("%lld\n",res);
	}else {
		printf("%lld\n",res);
	}
}
fire main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	in(T);
	while(T--) {
		solve();
	}
	return false;
}



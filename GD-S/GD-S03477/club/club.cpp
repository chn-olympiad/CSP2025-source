#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
#define ll int
#define ri register int
inline void write(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>=10) write(x/10);
	putchar('0'+x%10);
}
inline ll read(){
	ll r=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		r=(r<<1)+(r<<3)+(c^48);
		c=getchar();
	}
	return r*f;
}
inline ll Min(ll a,ll b){
	return a<b?a:b;
}
inline ll Max(ll a,ll b){
	return a>b?a:b;
}
const int N=1e5+5;
inline ll find_max(ll a,ll b,ll c){
	ll js=Max(a,Max(b,c));
	if(js==a) return 0;
	if(js==b) return 1;
	if(js==c) return 2;
}
ll t,n,m;
ll a[N],b[N],c[N];
ll jsa,jsb,jsc;
struct node{
	ll a,b,c;
	ll v,id;
};
struct qwq{
	int id,v;
	bool operator<(const qwq &k)const{
		return v<k.v;
	}
};
queue<node>q;
priority_queue<qwq>A,B;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		n=read();
		jsa=0,jsb=0,jsc=0;
		for(ri i=1;i<=n;i++){
			a[i]=read(),b[i]=read(),c[i]=read();
			if(a[i]==0) jsa++;
			if(b[i]==0) jsb++;
			if(c[i]==0) jsc++;
		}
		if((jsb==jsc&&jsb==n&&jsa<n)||(jsa==jsb&&jsb==n&&jsc<n)||(jsa==jsc&&jsa==n&&jsb<n)){
			if(jsa==n&&jsc==n) for(int i=1;i<=n;i++) a[i]=b[i];
			if(jsa==n&&jsb==n) for(int i=1;i<=n;i++) a[i]=c[i];
			sort(a+1,a+1+n);
			ll ans=0;
			for(int i=n;i>n/2;i--)
				ans+=a[i];
			write(ans);
			putchar('\n');
			continue;
		}
		if((jsc==n&&jsa<n&&jsb<n)||(jsb==n&&jsa<n&&jsc<n)||(jsa==n&&jsb<n&&jsc<n)){
			if(jsb==n) for(int i=1;i<=n;i++) b[i]=c[i];
			if(jsa==n) for(int i=1;i<=n;i++) a[i]=c[i];
			for(int i=1;i<=n;i++){
				if(a[i]<b[i]) B.push((qwq){i,b[i]});
				else A.push((qwq){i,a[i]});
			}
			if(A.size()>n/2){
				while(A.size()>n/2){
					B.push(A.top());
					A.pop();
				}
			}
			if(B.size()>n/2){
				while(B.size()>n/2){
					A.push(B.top());
					B.pop();
				}
			}
			ll ans=0;
			while(!A.empty()) ans+=A.top().v,A.pop();
			while(!B.empty()) ans+=B.top().v,B.pop();
			write(ans);
			putchar('\n');
			continue;
		}
		q.push((node){1,0,0,a[1],1});
		q.push((node){0,1,0,b[1],1});
		q.push((node){0,0,1,c[1],1});
		ll ans=0,js=0;
		while(!q.empty()){
			node d=q.front();
			q.pop();
			if(d.a>n/2) continue;
			if(d.b>n/2) continue;
			if(d.c>n/2) continue;
			if(d.a+d.b+d.c==n){
				ans=Max(ans,d.v);
				continue;
			}
			q.push((node){d.a+1,d.b,d.c,d.v+a[d.id+1],d.id+1});
			q.push((node){d.a,d.b+1,d.c,d.v+b[d.id+1],d.id+1});
			q.push((node){d.a,d.b,d.c+1,d.v+c[d.id+1],d.id+1});
		}
		write(ans);
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

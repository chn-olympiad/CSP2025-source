#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,ma,siz[4];
long long ans;
struct pii{ 
	int f,s,t,c;
	mca();
	bool operator < (const pii &p)const{
		return min(f,min(s,t))<min(p.f,min(p.s,p.t));
	}
}a[N];
struct pi{ //手写pair更有性价比 
	int f,s;
	bool operator < (const pi &t)const{
		return f<t.f;
	}
};
inline pii mca(pii t){ //最大与次大值 
	int ma,mai,mx,mxi;
	if(t.f>t.s&&t.f>t.t){
		ma=t.f,mai=1;
		mx=max(t.s,t.t);
		mxi=t.s>t.t?2:3;
	}else if(t.s>t.f&&t.s>t.t){
		ma=t.s,mai=2;
		mx=max(t.f,t.t);
		mxi=t.f>t.t?1:3;
	}else if(t.t>t.s&&t.t>t.f){
		ma=t.t,mai=3;
		mx=max(t.s,t.f);
		mxi=t.f>t.s?1:2;
	}
	return {ma,mai,mx,mxi};
}
bool cmp(pii a,pii b){
	pii c=mca(a),d=mca(b);
	return c.f-c.t>d.f-d.t;
}
inline void ch(priority_queue<pi> &q,pii t,int i){ //鼠鼠我啊贪一点 
	pii l=mca(a[q.top().s]);  
	if(t.t+l.f>t.f+l.t){ //原本更好 
		ans+=t.t;
		//懒得入队了,必定不会超过n/2 
	}else{ //新的更好 
		q.pop();
		ans=ans-l.f+t.f+l.t;
		q.push({t.t,i});
	} 
}
void solve(){ //美美得吃 
	memset(siz,0,sizeof siz);
	priority_queue<pi> q[4];
	scanf("%d",&n);
	ma=n>>1; //最大值n/2 (废话)
	ans=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i].f,&a[i].s,&a[i].t);
		a[i].c=i;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		pii t=mca(a[i]);
		if(siz[t.s]==ma) 
			ch(q[t.s],t,i);
		else q[t.s].push({t.t,i}),ans+=t.f,siz[t.s]++; //入 
	}
	printf("%lld\n",ans);
}
int main(){
	//记得改 
	// OK
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}


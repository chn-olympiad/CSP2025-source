#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int MAXN=1e5+5,mod=998244353,inf=0x3f3f3f3f;
int T,n;
struct ppl{
	int a,b,c;
}p[MAXN];
int ans;
bool cmp1(const ppl &x,const ppl &y){
	return x.a-max(x.b,x.c)>y.a-max(y.b,y.c);
}
bool cmp2(const ppl &x,const ppl &y){
	return x.b-max(x.a,x.c)>y.b-max(y.a,y.c);
}
bool cmp3(const ppl &x,const ppl &y){
	return x.c-max(x.a,x.b)>y.c-max(y.a,y.b);
}
void solve(){
	ans=0;
	cin>>n;
	int cnt1=0,cnt2=0,cnt3=0;
	for(int i=1;i<=n;i++){
		cin>>p[i].a>>p[i].b>>p[i].c;
		int maxn=max({p[i].a,p[i].b,p[i].c});
		if(p[i].a==maxn)
			++cnt1;
		if(p[i].b==maxn)
			++cnt2;
		if(p[i].c==maxn)
			++cnt3;
	}
	int now=max({cnt1,cnt2,cnt3});
	if(now==cnt1){
		int t=0;
		int cnt=min(now,n>>1);
		sort(p+1,p+n+1,cmp1);
		for(int i=1;i<=n;i++){
			if(!cnt||p[i].a<=max(p[i].b,p[i].c))
				t+=max(p[i].b,p[i].c);
			else
				t+=p[i].a,--cnt;
		}
		ans=max(ans,t);
	}
	if(now==cnt2){
		int t=0;
		int cnt=min(now,n>>1);
		sort(p+1,p+n+1,cmp2);
		for(int i=1;i<=n;i++){
			if(!cnt||p[i].b<=max(p[i].a,p[i].c))
				t+=max(p[i].a,p[i].c);
			else
				t+=p[i].b,--cnt;
		}
		ans=max(ans,t);
	}
	if(now==cnt3){
		int t=0;
		int cnt=min(now,n>>1);
		sort(p+1,p+n+1,cmp3);
		for(int i=1;i<=n;i++){
//			cerr<<i<<"-th: "<<"("<<p[i].a<<", "<<p[i].b<<", "<<p[i].c<<")\n";
			if(!cnt||p[i].c<=max(p[i].a,p[i].b))
				t+=max(p[i].a,p[i].b);
			else
				t+=p[i].c,--cnt;
		}
		ans=max(ans,t);
	}
	cout<<ans<<"\n";
}
/*
1
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
*/
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>T;
	while(T--)
		solve();
	return 0;
}


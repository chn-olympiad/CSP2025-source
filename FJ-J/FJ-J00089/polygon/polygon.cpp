#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MOD=998244353;

int n,l[10009],v[10009],vv[10009],ans=0;

struct POL{
	int o[10009],s,ssum=0,smax=0;
	void init(){
		for(int i=0;i<10009;i++)o[i]=0;
		s=ssum=smax=0;
	}
	void add(int ll){
		o[s++]=ll;
		ssum+=l[ll];
		smax=max(smax,l[ll]);
	}
	bool pol(){
		return ssum>2*smax&&s>=3;
	}
}p;

int vvv(POL l){
	int _v=1;
	for(int i=0;i<l.s;i++){
		_v*=l.o[i];
		_v%=10009;
	}
	_v+=l.s*l.smax*l.ssum;
	_v%=10009;
	return _v;
}

void dfs(int k){
	if(k>n)return;
	if(p.pol()&&vv[vvv(p)]==0){
		vv[vvv(p)]=1;
		ans++;
		ans%=MOD;
	}
	p.init();
	for(int i=0;i<n;i++){
		if(v[i]==1)p.add(i);
	}
	v[k]=1;
	dfs(k+1);
	v[k]=0;
	dfs(k+1);
}

signed main(void){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=0;i<n;i++){
		scanf("%lld",&l[i]);
	}
	
	p.init();
	dfs(0);
	
	printf("%lld",ans);
	return 0;
}
/*
5
2 2 3 8 10

6
----
5
1 2 3 4 5

9
*/


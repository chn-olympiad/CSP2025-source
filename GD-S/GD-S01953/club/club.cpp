#include <bits/stdc++.h>
using namespace std;
#define fi first
#define sc second
int t,n,a[10],s[100007],v,c,g,cnt[10];
long long ans;
bool f[10];
priority_queue<pair<int,pair<int,int> > >pq;
priority_queue<pair<int,int> >q[100007];
int fc(int x,int y,int z){
	if(x<y){
		if(y<z) return y;
		else if(x<z) return z;
		else return x;
	}else{
		if(y>z) return y;
		else if(x>z) return z;
		else return x;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0;
		for(int i=1;i<=3;++i) cnt[i]=0,f[i]=0;
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=3;++j) scanf("%d",&a[j]);
			s[i]=fc(a[1],a[2],a[3]);
			for(int j=1;j<=3;++j){
				a[j]-=s[i];
				q[i].push({a[j],j});
			}
			auto p=q[i].top();
			q[i].pop();
			pq.push({p.fi,{i,p.sc}});
		}
		while(!pq.empty()){
			auto p=pq.top();
			pq.pop();
			v=p.fi,c=p.sc.fi,g=p.sc.sc;
			if(f[g]){
				auto pp=q[c].top();
				pq.push({pp.fi,{c,pp.sc}});
				q[c].pop();
				continue;
			}
			++cnt[g];
			if(cnt[g]>=n/2) f[g]=1;
			ans+=v+s[c];
		}
		cout<<ans<<"\n";
	}
	return 0;
}

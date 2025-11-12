#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;

int t,n;

struct C{
	int id;
	ll v,s;
};

struct P{
	C c[4];
}p[N];

int cnt[4];
ll ans;

bool Cmp1(C x,C y){
	return x.v>y.v;
}

bool Cmp2(P x,P y){
	for(int i=1;i<=3;++i){
		if(x.c[i].s!=y.c[i].s){
			return x.c[i].s<y.c[i].s;
		} 
	}
	return 1;
}

void Solve(){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=3;++j){
			int id=p[i].c[j].id;
			ll v=p[i].c[j].v;
			if(cnt[id]<n/2){
				++cnt[id];
				ans+=v;
				break;
			}
		}
	}
	cout<<ans<<"\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=3;++j){
				cin>>p[i].c[j].v;
				p[i].c[j].id=j;
			}
			sort(p[i].c+1,p[i].c+4,Cmp1);
			p[i].c[1].s=0;
			p[i].c[2].s=p[i].c[2].v-p[i].c[1].v; 
			p[i].c[3].s=p[i].c[3].v-p[i].c[2].v;
		}
		sort(p+1,p+n+1,Cmp2);
		ans=cnt[1]=cnt[2]=cnt[3]=0;
		Solve();
	}
	
	return 0;
}


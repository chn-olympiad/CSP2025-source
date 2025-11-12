#include<bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x":"<<(x)<<' '
#define dbe(x) cerr<<#x":"<<(x)<<'\n'
#define eb emplace_back
#define ep emplace
#define endl '\n'
using ll=long long;
using vi=vector<int>;
using vl=vector<ll>;
using tp=tuple<int,int>;
ll ANS=1e18;
ll ZXSCS(int n,vector<vector<tp>>&bian){
	vi b(n+1);
	priority_queue<tp,vector<tp>,greater<tp>>pq;
	pq.ep(0,1);
	ll sum=0;
	while(!pq.empty()){
		auto [w,u]=pq.top();pq.pop();
		if(b[u])continue;
		b[u]=1;
		sum+=w;
		if(sum>ANS)return 1e18;
		for(auto [v,w]:bian[u]){
			if(b[v])continue;
			pq.ep(w,v);
		}
	}
	return sum;
}
using tpl=tuple<int,ll>;
auto ZXSCS2(int n,vector<vector<tp>>&bian,int st){
	using tp3=tuple<int,int,int>;
	vi b(n+1);
	vi fm(n+1);
	priority_queue<tp3,vector<tp3>,greater<tp3>>pq;
	pq.ep(0,st,0);
	ll sum=0;
	while(!pq.empty()){
		auto [w,u,f]=pq.top();pq.pop();
		if(b[u])continue;
		b[u]=1;
		sum+=w;
		fm[u]=w;
		for(auto [v,w]:bian[u]){
			if(b[v])continue;
			pq.ep(w,v,u);
		}
	}
	return tuple<ll,vi>({sum,fm});
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n,m,k;
	cin>>n>>m>>k;
	vector<vector<tp>>bian(n+1);
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		bian[u].eb(v,w);
		bian[v].eb(u,w);
	}
	vi c(k+1);
	vector<vi>a(k+1,vi(n+1));
	bool XZA=true;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0)XZA=false;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]!=0)XZA=false;
		}
	}
	if(XZA){
		bian.resize(n+k+1);
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				bian[i+n].eb(j,a[i][j]);
				bian[j].eb(i+n,a[i][j]);
			}
		}
		cout<<ZXSCS(n+k,bian)<<endl;
		return 0;
	}
	else if(k>5&&m>4e5&&n>1e3){
		ll ans=1e18;
		for(int XXX=1;XXX<=2;XXX++){
		
		auto [SUM,fm]=ZXSCS2(n,bian,XXX);
		dbe(SUM);
		for(int i=1;i<=n;i++)cerr<<fm[i]<<" \n"[i==n];
		fm.resize(n+k+1);
		for(int i=0;i<(1<<k);i++){
			dbe(i);
			ll sum=0;
			auto fm2=fm;
			for(int j=0;j<k;j++){
				if(!(i>>j&1))continue;
				sum+=c[j+1];
				ll dis=1e18;int x=0;
				for(int l=1;l<=n;l++){
					dbg(l),dbe(a[j+1][l]);
					if(a[j+1][l]<dis)dis=a[j+1][l],x=l;
				}
				dbg(j),dbg(dis),dbe(x);
				sum+=dis;
				for(int l=1;l<=n;l++){
					if(l==x)continue;
					int d=fm2[l];
					dbg(l),dbg(d),dbe(a[j+1][l]);
					if(d>a[j+1][l]){
						sum-=d,sum+=a[j+1][l];
						fm2[l]=a[j+1][l];
					}
				}
			}
			dbe(sum);
			ll o=SUM+sum;
			ans=min(ans,o);
			//cerr<<i<<' '<<ans<<' '<<o<<endl;
		}
		
		}
		cout<<ans<<endl;
	}else{
		
		ll ans=1e18;
		bian.resize(n+k+1);
		for(int i=0;i<(1<<k);i++){
			ll sum=0;
			auto bian2=bian;
			for(int j=0;j<k;j++){
				if(!(i>>j&1))continue;
				sum+=c[j+1];
				for(int l=1;l<=n;l++){
					bian2[j+n+1].eb(l,a[j+1][l]);
					bian2[l].eb(j+n+1,a[j+1][l]);
				}
			}
			ll o=ZXSCS(n+k,bian2)+sum;
			ans=min(ans,o);
			ANS=ans;
			//cerr<<i<<' '<<ans<<' '<<o<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}
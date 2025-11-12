#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
struct Edge{
	Edge(int a,int b,int c):x(a),y(b),z(c){}
	int x,y,z;
};
int n,m,k,x,y,z,ans=LLONG_MAX,c[10],f[10005];
vector<Edge> ces[10];
vector<Edge> es;
int Findf(int x){
	if(f[x]==x) return x;
	return f[x]=Findf(f[x]);
}
bool cmp(Edge a,Edge b){
	return a.z<b.z; 
}
void Gentree(vector<Edge> &ev){
	vector<Edge> ans;
	for(int i=1;i<=n+k;i++) f[i]=i;
	for(int i=0;i<ev.size();i++){
		int x=ev[i].x,y=ev[i].y;
		if(Findf(x)==Findf(y)) continue;
		f[Findf(x)]=Findf(y);
		ans.push_back(ev[i]);
	} 
	ev=ans;
}
void Insert(vector<Edge> &X,const vector<Edge> &Y){
	vector<Edge> ans;
	int Xptr=0,Yptr=0;
	while((Xptr<X.size()||Yptr<Y.size())){
		if(Xptr==X.size()) ans.push_back(Y[Yptr++]);
		else if(Yptr==Y.size()) ans.push_back(X[Xptr++]);
		else{
			if(X[Xptr].z<Y[Yptr].z) ans.push_back(X[Xptr++]);
			else ans.push_back(Y[Yptr++]);
		}
	}
	X=ans;
}
int Count(const vector<Edge> &v){
	int ans=0;
	for(int i=0;i<v.size();i++){
		ans+=v[i].z;
	} 
	return ans;
}
void Merge(vector<Edge> &v,int l,int r,int S){
	if(l==r){
		if(S&(1<<l)) Insert(v,ces[l]);
		return;
	}
	Merge(v,l,(l+r)/2,S);
	vector<Edge> v2;
	Merge(v2,(l+r)/2+1,r,S);
	Insert(v,v2);
}
//mt19937 rnd(114514);
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
//	n=10000,m=1000000,k=10;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
//		x=rnd()%n+1,y=rnd()%n+1,z=rnd();
		es.push_back(Edge(x,y,z));
	}
	for(int i=0;i<k;i++){
		cin>>c[i];
//		c[i]=rnd();
		for(int j=1;j<=n;j++){
			cin>>z;
//			z=rnd();
			ces[i].push_back(Edge(i+n+1,j,z));
		}
		sort(ces[i].begin(),ces[i].end(),cmp);
	}
//	cout<<clock()/1e3<<endl;
	sort(es.begin(),es.end(),cmp);
	Gentree(es);
	vector<int> V;
	for(int i=0;i<(1<<k);i++){
		V.push_back(i);
	}	
	random_shuffle(V.begin(),V.end());
	for(int I=0;I<(1<<k);++I){
		int i=V[I];
		vector<Edge> tes=es;
		int cnt=0;
		for(int j=0;j<k;++j){
			if((i&(1<<j))==0) continue;
			cnt+=c[j];
		}
		Merge(tes,0,k-1,i);
		Gentree(tes);
		cnt+=Count(tes);
		ans=min(ans,cnt); 
//		for(int j=0;j<tes.size();j++){
//			cout<<tes[j].x<<" <--> "<<tes[j].y<<" : "<<tes[j].z<<endl;
//		}
//		cout<<i<<" "<<cnt<<endl;
//		cout<<clock()/1e3<<endl;
		if(clock()>CLOCKS_PER_SEC-100){
			break;
		}
	}
	cout<<ans; 
	return 0; 
}

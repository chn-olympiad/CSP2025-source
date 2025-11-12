#include <bits/stdc++.h>
using namespace std;
long long n,m,k,sum=0;
long long fa[100000];
struct Line{
	long long u;
	long long v;
	long long w;
	Line(long long u_=0,long long v_=0,long long w_=0){
		u=u_;
		v=v_;
		w=w_;
	}
};
vector<Line> v;
void csh(){
	for(int i=0;i<100000;i++){
		fa[i]=i;
	}
}
long long find(long long x){
	if(x==fa[x])return x;
	else return fa[x]=find(fa[x]);
}
bool cr(long long a,long long b){
	long long ga=find(a),gb=find(b);
	if(ga!=gb){
		fa[ga]=gb;
		return true;
	}
	return false;
}
bool cmp(const Line& a,const Line& b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		long long u,v2,w;
		cin >> u >> v2 >> w;
		v.push_back({u,v2,w});
	}
	sort(v.begin(),v.end(),cmp);
	csh();
	for(auto i:v){
		if(cr(i.u,i.v))sum+=i.w;
	}
	cout << sum;
	return 0;
} 

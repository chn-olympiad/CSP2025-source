#include<bits/stdc++.h>
using namespace std;
#define int long long
#define re register
#define il inline
#define pii pair<int,int>
#define x first
#define y second
#define rd read()
#define gc getchar()
#define debug() puts("-----------")

namespace yzqwq{
	il int read(){
		int x=0,f=1;char ch=gc;
		while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=gc;}
		while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=gc;
		return x*f;
	}
	il int qmi(int a,int b,int p){
		int res=1;
		while(b){
			if(b&1) res=res*a%p;
			a=a*a%p,b>>=1;
		}
		return res;
	}
	il int gcd(int a,int b){
		if(!b) return a;
		return gcd(b,a%b);
	}
	il void exgcd(int a,int b,int &x,int &y){
		if(!b) return x=1,y=0,void(0);
		exgcd(b,a%b,y,x);
		y-=a/b*x;
		return ;
	}
	mt19937 rnd(time(0));
}
using namespace yzqwq;

const int N=1e5+10;
int n;
int a[N][4],id[N][4],b[4],c[4];
priority_queue<pii,vector<pii>,greater<pii>> q[4];

il void solve(){
	n=rd;
	for(re int i=1;i<=3;++i) while(!q[i].empty()) q[i].pop();
	for(re int i=1;i<=n;++i)
	for(re int j=1;j<=3;++j) a[i][j]=rd;
	for(re int i=1;i<=n;++i){
		for(re int j=1;j<=3;++j) b[j]=a[i][j],c[j]=j;
		sort(c+1,c+3+1,[](int x,int y){
			return b[x]>b[y];
		});
		for(re int j=1;j<=3;++j) id[i][j]=c[j];
		q[id[i][1]].push({a[i][id[i][1]],i});
	}
	int res=0;
	int Mx=0,dd=0;
	for(re int j=1;j<=3;++j) Mx=max(Mx,(int)(q[j].size()));
	for(re int j=1;j<=3;++j) if(Mx==(int)(q[j].size())) dd=j;
	if(Mx<=n/2){
		for(re int i=1;i<=3;++i)
		while(!q[i].empty()) res+=(int)(q[i].top().x),q[i].pop();
		cout<<res<<"\n";
		return ;
	}
	vector<int> vec;vec.clear();
	while(!q[dd].empty()) res+=(int)(q[dd].top().x),vec.push_back((int)(q[dd].top().y)),q[dd].pop();
	for(re int i=1;i<=3;++i){
		while(!q[i].empty()) res+=(int)(q[i].top().x),q[i].pop();
	}
	vector<int> v_;v_.clear();
	for(auto x:vec){
		v_.push_back(-a[x][id[x][1]]+a[x][id[x][2]]);
	}int uu=(int)(vec.size());
	sort(v_.begin(),v_.end());
	reverse(v_.begin(),v_.end());
	for(re int j=0;uu>n/2;++j,--uu){
		res+=v_[j];
	}cout<<res<<"\n";
	return ;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=rd;while(t--)
	solve();
	return 0;
}

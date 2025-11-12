#include<bits/stdc++.h>
using namespace std;
#define freop(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout);
#define ll long long
#define ld long double
#define inf 0x7f7f7f7f
#define endl '\n'
#define lb(x) ((x)&-(x))
#define pii pair<int,int>
#define piii pair<int,pii>
#define fir first
#define sec second.first
#define thi second.second
const int N=1e5+1;
int T,n,ans,d[N];
piii in[N];
vector<int> a,b,c;

inline bool cmp(int x,int y){return d[x]<d[y];}

int main(){
	cin.tie(0)->ios::sync_with_stdio(0);
	cout.tie(0);
	freop("club");
//以上为初始化
//--------------------------------------
	cin >> T;
	while(T--){
		cin >> n,ans=0,a.clear(),b.clear(),c.clear();
		for(int i = 1;i<=n;++i){
			cin >> in[i].fir >> in[i].sec >> in[i].thi;
			if(in[i].fir>=max(in[i].sec,in[i].thi)) ans+=in[i].fir,a.push_back(i);
			else if(in[i].sec>=max(in[i].fir,in[i].thi)) ans+=in[i].sec,b.push_back(i);
			else ans+=in[i].thi,c.push_back(i);
			if(in[i].fir<in[i].sec) swap(in[i].fir,in[i].sec);
			if(in[i].sec<in[i].thi) swap(in[i].sec,in[i].thi);
			if(in[i].fir<in[i].sec) swap(in[i].fir,in[i].sec);
			d[i]=in[i].fir-in[i].sec;
		}
		n>>=1;
		if(a.size()>n){
			sort(a.begin(),a.end(),cmp);
			for(int i = 0;i<a.size()-n;++i) ans-=d[a[i]];
		}else if(b.size()>n){
			sort(b.begin(),b.end(),cmp);
			for(int i = 0;i<b.size()-n;++i) ans-=d[b[i]];
		}else if(c.size()>n){
			sort(c.begin(),c.end(),cmp);
			for(int i = 0;i<c.size()-n;++i) ans-=d[c[i]];
		}
		cout << ans << endl;
	}
	return 0;
}
/*

*/

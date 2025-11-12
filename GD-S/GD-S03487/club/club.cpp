#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
struct person{
	int a,b,c;
};
bool cmp(person& a,person& b){
	if(a.a==b.a){
		if(a.b == b.b)return a.c>b.c;
		return a.b>b.b;
	}
	return a.a>b.a;
}
const int mod = 1e5;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	//cout<<"here\n"; 
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<person>p(n+1);
		for(int i=1;i<=n;i++){
			cin>>p[i].a>>p[i].b>>p[i].c;
		}
		int eg = n>>1;
		long long ans=0;
		if(n<=10){
			sort(p.begin()+1, p.begin()+n+1, cmp);\
			int cnt0=0,cnt1=0,cnt2=0;
			for(int i=1;i<=n;i++){
				if(p[i].a>p[i].b&&p[i].a>p[i].c&&cnt0<eg){
					cnt0++;
					ans+=p[i].a;
				}else if(p[i].b>p[i].a&&p[i].b>p[i].c&&cnt1<eg){
					cnt1++;
					ans+=p[i].b;
				}else{
					cnt2++;
					ans+=p[i].c;
				}
			}
			cout<<ans<<'\n';
			continue;
		} 
		vector<person>f(mod,{0,0,0});
		f[0]={0,0,0};
		queue<long long>eachj[2];
		eachj[0].push(p[1].a);
		eachj[0].push(p[1].b);
		eachj[0].push(p[1].c);
		for(int i = 2;i <= n;i++){
			int nxq = i % 2, nxt = (i+1) % 2;
			while(!eachj[nxq].empty()){
				long long j = eachj[nxq].front();
				eachj[nxq].pop();
				person& now = f[j];
				if(now.a + now.b + now.c >= n){
					ans = max(ans,j);
					continue;
				}
				long long _mj = j % mod;
				if(now.a<eg){
					f[(_mj + p[i].a)%mod]={now.a + 1,now.b,now.c};
					eachj[nxt].push(j + p[i].a);
				}
				if(now.b<eg){
					f[(_mj + p[i].b)%mod]={now.a,now.b + 1,now.c};
					eachj[nxt].push(j + p[i].b);
				}
				if(now.c<eg){
					f[(_mj + p[i].c)%mod]={now.a,now.b,now.c + 1};
					eachj[nxt].push(j + p[i].c);
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

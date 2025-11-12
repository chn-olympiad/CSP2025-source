#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using ll=long long;
int n,a[N][3];
int ton[3];
struct myd{
	int x,v;
	inline bool operator >(const myd &B)const{
		return v>B.v;
	}
};
struct node{
	myd ma,se;
	inline void init(){
		ma=se={0,-1};
	}
	inline void ins(myd v){
		if(v>ma)se=ma,ma=v;
		else if(v>se)se=v;
	}
}b[N];
ll ans;
void solve(){
	cin>>n;
	ans=0;
	ton[0]=ton[1]=ton[2]=0;
	for(int i=1;i<=n;i++){
		b[i].init();
		for(int j=0;j<3;j++){
			cin>>a[i][j];
			b[i].ins({j,a[i][j]});
		}
		ton[b[i].ma.x]++;
		ans+=b[i].ma.v;
	}
	vector<int>id={0,1,2};
	sort(id.begin(),id.end(),[&](const int A,const int B){
		return ton[A]>ton[B];
	});
	int pos=id[0];
	if(ton[pos]<=n/2){
		cout<<ans<<"\n";
		return ;
	}
	vector<int>rea;
	for(int i=1;i<=n;i++){
		if(b[i].ma.x==pos){
			rea.push_back(b[i].ma.v-b[i].se.v);
		}
	}
	sort(rea.begin(),rea.end());
	for(int i=0;i<ton[pos]-n/2;i++){
		ans-=rea[i];
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--)solve(); 
	return 0;
} 
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
bool tmp(vector<int> A,vector<int> B){
	int ama=max({A[1],A[2],A[3]}),bma=max({B[1],B[2],B[3]});
	int ami=min({A[1],A[2],A[3]}),bmi=min({B[1],B[2],B[3]});
	int amd=A[1]+A[2]+A[3]-ama-ami,bmd=B[1]+B[2]+B[3]-bma-bmi;
	if(ama!=bma)return ama>bma;
	if(amd!=bmd)return amd>bmd;
	return ami>bmi;
}
void solve(){
	int pjn;cin>>pjn;
	vector<vector<int> > A(pjn+1,vector<int>(4));
	for(int i=1;i<=pjn;i++){
		cin>>A[i][1]>>A[i][2]>>A[i][3];
	}
	sort(begin(A)+1,end(A),tmp);
	ll ans=0;
	vector<ll> club(4);
	for(ll i=1;i<=pjn;i++){
		int ma=max({A[i][1],A[i][2],A[i][3]});
		int mi=min({A[i][1],A[i][2],A[i][3]});
		int md=A[i][1]+A[i][2]+A[i][3]-ma-mi;
		int mad=(ma==A[i][1]?1:(ma==A[i][2]?2:3));
		int mid=(mi==A[i][1]?1:(mi==A[i][2]?2:3));
		int mdd=(md==A[i][1]?1:(md==A[i][2]?2:3));
		int x=(club[mad]<pjn/2?mad:(club[mdd]<pjn/2?mdd:mid));
		ans+=1ll*A[i][x];
		club[x]++;
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int pjt;cin>>pjt;
	while(pjt--)solve();
	return 0;
}

//GZ-S00140 贵州省织金育才学校 宋载航 
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
const ll N=1e5+9,M=1e6+9,INF=0x3f3f3f3f3f3f3f3f;
ll T=1;
ll n,q;
string st[N][2],q0,q1;
//string qz[200][2];
string hz[200][2];
inline void solve(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>st[i][0]>>st[i][1];
	}
	for(int i=1;i<=q;i++){
		cin>>q0>>q1;
		ll cnt=0;
		ll mid=INF,mxd=0;
		for(ll i=0;i<q0.size();i++){
			if(q0[i]!=q1[i]){
				mid=min(mid,i);
				mxd=max(mxd,i);
			}
//			qz[i][0]=qz[i-1][0]+q0[i];
//			qz[i][1]=qz[i-1][1]+q1[i];
		}
		for(int i=q0.size()-1;i>=0;i--){
			hz[i][0]=q0[i]+hz[i+1][0];
			hz[i][1]=q1[i]+hz[i+1][1];
		}
		for(int i=-1;i<mid;i++){
			for(int j=mxd+1;j<=q0.size();j++){
				string mi0=hz[i+1][0],mi1=hz[i+1][1];
				if(j<q0.size()){
					mi0.erase(j-i-1);
					mi1.erase(j-i-1);
				}
//				cout<<mi0<<" "<<mi1<<"\n";
				for(int k=1;k<=n;k++){
					if(st[k][0]==mi0&&st[k][1]==mi1){
						cnt++;
					}
				}
			}
		}
		cout<<cnt<<"\n";
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}

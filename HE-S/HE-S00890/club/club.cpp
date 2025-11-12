#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MXN=1e5+5;
int T,n,to[MXN];
ll a[MXN][3];
vector<ll>vec;
ll run(){
	ll ans=0,cnt[3]={};
	cin>>n;
	for(int i=0;i<n;i++){
		ll mxv=LLONG_MIN;
		int mxp=-1;
		for(int j=0;j<3;j++){
			cin>>a[i][j];
			if(mxv<a[i][j])mxv=a[i][j],mxp=j;
		}
		to[i]=mxp;
		cnt[mxp]++;
		ans+=mxv;
	}
	int over=-1;
	for(int i=0;i<3;i++)if(cnt[i]>n/2)over=i;
	if(over==-1)return ans;
	vec.clear();
	for(int i=0;i<n;i++){
		if(to[i]!=over)continue;
		ll sec=LLONG_MIN;
		for(int j=0;j<3;j++)
			if(j!=over)sec=max(sec,a[i][j]);
		vec.push_back(a[i][over]-sec);
	}
	sort(vec.begin(),vec.end());
	for(int i=0;i<cnt[over]-n/2;i++)ans-=vec[i];
	return ans;
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cout<<run()<<endl;
	}
}

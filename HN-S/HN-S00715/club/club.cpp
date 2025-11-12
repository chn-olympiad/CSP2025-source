#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N=1e5+5;
ll t,n,a[N][4];
vector<ll> tmp[4];

bool cmp1(ll x,ll y){
	return (a[x][1]-max(a[x][2],a[x][3]))<(a[y][1]-max(a[y][2],a[y][3]));
}
bool cmp2(ll x,ll y){
	return (a[x][2]-max(a[x][1],a[x][3]))<(a[y][2]-max(a[y][1],a[y][3]));
}
bool cmp3(ll x,ll y){
	return (a[x][3]-max(a[x][2],a[x][1]))<(a[y][3]-max(a[y][2],a[y][1]));
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		tmp[1].clear();
		tmp[2].clear();
		tmp[3].clear();
		for(ll i=1;i<=n;i++)
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		ll ans=0;
		for(ll i=1;i<=n;i++){
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])tmp[1].push_back(i),ans+=a[i][1];
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])tmp[2].push_back(i),ans+=a[i][2];
			else tmp[3].push_back(i),ans+=a[i][3];
		}
//		cout<<ans<<'\n';
		if(tmp[1].size()*2>n){
//			cout<<"1\n";
//			cout<<tmp[1].size()<<'\n';
			sort(tmp[1].begin(),tmp[1].end(),cmp1);
			for(ll i=0;tmp[1].size()-i>n/2;i++){
//				cout<<i<<' ';
				ans+=max(a[tmp[1][i]][2],a[tmp[1][i]][3])-a[tmp[1][i]][1];
			}
//			cout<<'\n';
		}
		if(tmp[2].size()*2>n){
//			cout<<"2\n";
//			cout<<tmp[2].size()<<'\n';
			sort(tmp[2].begin(),tmp[2].end(),cmp2);
			for(ll i=0;tmp[2].size()-i>n/2;i++){
//				cout<<i<<' ';
				ans+=max(a[tmp[2][i]][1],a[tmp[2][i]][3])-a[tmp[2][i]][2];
			}
//			cout<<'\n';
		}
		if(tmp[3].size()*2>n){
//			cout<<"3\n";
//			cout<<tmp[3].size()<<'\n';
			sort(tmp[3].begin(),tmp[3].end(),cmp3);
			for(ll i=0;tmp[3].size()-i>n/2;i++){
//				cout<<i<<' ';
				ans+=max(a[tmp[3][i]][2],a[tmp[3][i]][1])-a[tmp[3][i]][3];
			}
//			cout<<'\n';
		}
		cout<<ans<<'\n';
	}
	return 0;
}
// shen ren ji zi gei wo zha liang ci,bu guo zhuo mo chu le t1 ans
// yi qie dou shi ming yun shi zhi men de xuan ze,El Psy Congroo

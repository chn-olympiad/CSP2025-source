#include<bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x":"<<(x)<<' '
#define dbe(x) cerr<<#x":"<<(x)<<'\n'
#define eb emplace_back
#define ep emplace
#define endl '\n'
using ll=long long;
using vi=vector<int>;
using vl=vector<ll>;
using tp=tuple<int,int>;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		vector<vi>a(3,vi(n+1));
		vector<vi>lst(3);
		vl sum(3);
		for(int i=1;i<=n;i++){
			cin>>a[0][i]>>a[1][i]>>a[2][i];
			int x=max({a[0][i],a[1][i],a[2][i]});
			if(a[0][i]==x)lst[0].eb(i),sum[0]+=x;
			else if(a[1][i]==x)lst[1].eb(i),sum[1]+=x;
			else if(a[2][i]==x)lst[2].eb(i),sum[2]+=x;
		}
		if(lst[0].size()<=n/2&&lst[1].size()<=n/2&&lst[2].size()<=n/2){
			cout<<sum[0]+sum[1]+sum[2]<<endl;
			continue;
		}
		int o=0;
		if(lst[0].size()>n/2)o=0;
		else if(lst[1].size()>n/2)o=1;
		else if(lst[2].size()>n/2)o=2;
		vi lst2;
		for(auto v:lst[o]){
			int mn=1e9;
			for(int i=0;i<3;i++){
				if(i!=o)mn=min(mn,a[o][v]-a[i][v]);
			}
			lst2.eb(mn);
		}
		sort(lst2.begin(),lst2.end());
		ll S=sum[0]+sum[1]+sum[2];
		for(int i=0;i<int(lst[o].size()-n/2);i++){
			S-=lst2[i];
		}
		cout<<S<<endl;
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
namespace qwq{
	const int N=1e5+114;
	typedef pair<int,int> pint;
	int a[N][3],n,in[N],cnt[3];
	signed mian(){
		int t;
		cin >> t;
		while(t--){
			cin >> n;
			for(int i=1;i<=n;++i) cin >> a[i][0] >> a[i][1] >> a[i][2];
			cnt[0]=cnt[1]=cnt[2]=0;
			for(int i=1;i<=n;++i){
				if(a[i][0]>a[i][1] && a[i][0]>a[i][2]){
					++cnt[0];
					in[i]=0;
				}
				else if(a[i][1]>a[i][2]){
					++cnt[1];
					in[i]=1;
				}
				else{
					++cnt[2];
					in[i]=2;
				}
			}
			if(cnt[0]>n/2 || cnt[1]>n/2 || cnt[2]>n/2){
				int o0=-1,o1=-1,o2=-1;
				if(cnt[0]>n/2) o0=0,o1=1,o2=2;
				else if(cnt[1]>n/2) o0=1,o1=0,o2=2;
				else o0=2,o1=0,o2=1;
				vector<pint> vec;
				for(int i=1;i<=n;++i){
					if(in[i]==o0){
						vec.push_back(pint(a[i][o0]-max(a[i][o1],a[i][o2]),i));
					}
				}
				sort(vec.begin(),vec.end());
				for(int i=0;i<cnt[o0]-n/2;++i){
					in[vec[i].second]=(a[vec[i].second][o1]>a[vec[i].second][o2]?o1:o2);
				}
			}
//			for(int i=1;i<=n;++i) cout << in[i] << " ";
//			cout << "\n";
			int ans=0;
			for(int i=1;i<=n;++i) ans+=a[i][in[i]];
			cout << ans << "\n";
		}
		return 0;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	qwq::mian();
	return 0;
}

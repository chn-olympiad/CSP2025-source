#include <iostream>
#include <algorithm>
using namespace std;

int cnt[3];
pair<int,int> c[100005][3];
int n,ans = 0,t;

pair<int,int> prs[100005];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		ans = 0;
		cnt[0] = cnt[1] = cnt[2] = 0;
		for(int i = 1;i <= n; i++){
			int c1,c2,c3;
			cin >> c1 >> c2 >> c3;
			c[i][0] = {-c1,0},c[i][1] = {-c2,1},c[i][2] = {-c3,2};
			sort(c[i],c[i] + 3);
			prs[i] = {c[i][1].first-c[i][0].first,i};
			cnt[c[i][0].second]++;
			ans -= c[i][0].first;
		}
		sort(prs + 1,prs + n + 1);
		for(int i = 0;i < 3; i++) if(cnt[i] > n / 2)
			//throw away extra people.
			for(int j = 1;j <= n; j++) if(c[prs[j].second][0].second == i){
				cnt[i]--;
				ans -= prs[j].first;
				cnt[c[prs[j].second][1].second]++;
				if(cnt[i] == n / 2) break;
			}
		cout << ans << endl;
	}
	
	
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10,M=2e4+10;
struct stu {
	int best;
	int ci;
	int bestv=-1;
	int civ=-1;
	bool operator < (const stu &other) {
		return bestv-civ > other.bestv - other.civ;
	}
};
int n,ret=0;
vector<stu> v;
int bkt[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while (T--) {
		memset(bkt,0,sizeof(bkt));
		v.clear();
		ret=0;
		scanf("%d",&n);
		for (int i = 0; i < n; i++) {
			v.emplace_back();
			for (int j = 0; j < 3; j++) {
				int tmp;
				scanf("%d",&tmp);
				if (tmp > v[i].bestv) {
					v[i].civ = v[i].bestv;
					v[i].ci = v[i].best;
					v[i].bestv = tmp;
					v[i].best = j;
				} else if (tmp > v[i].civ) {
					v[i].civ = tmp;
					v[i].ci = j;
				}
			}
		}
		sort(v.begin(),v.end());
		for (int i = 0; i < v.size(); i++) {
			if (bkt[v[i].best] + 1 <= n / 2) {
				bkt[v[i].best]++;
				ret += v[i].bestv;
			} else {
			 	bkt[v[i].ci]++;
			 	ret += v[i].civ;
			 	
			}
		}
		printf("%d\n",ret);
	}
	return 0;
}

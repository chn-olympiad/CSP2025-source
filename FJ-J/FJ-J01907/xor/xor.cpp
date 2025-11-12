#include<bits/stdc++.h>
#define int long long
const int N = 5e5+10;
int n, k;
int a[N];
int sum[N];
std::vector<std::pair<int,int> > v;
int len = 0;
signed main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	std::cin>>n>>k;
	for (int i = 1; i <= n; i++) {
		scanf("%ld",&a[i]);
		sum[i] = sum[i-1] ^ a[i];
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j+i-1 <= n; j += 1) {
			if ((sum[j+i-1] ^ sum[j-1]) != k) continue;
			bool s = true;
//			std::cout<<j<<" "<<j+i-1<<":\n";
			for (int l = 0; l < v.size(); l++) {
//				std::cout<<v[l].first<<" "<<v[l].second<<std::endl;
				if (!((j+i-1 < v[l].first) || (j > v[l].second))) {
					s = false;
					break;
				}
			}
			if (s) {
				std::pair<int,int> q;
				q.first = j,q.second = j+i-1;
				v.push_back(q);
				ans++;
//				std::cout<<q.first<<" "<<q.second<<"\n";
			}
		}
	}
	printf("%ld",ans);
	return 0;
}

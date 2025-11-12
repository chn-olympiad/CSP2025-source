#include <bits/stdc++.h>
using namespace std;
#define int long long
int N;
int Cnt[3];
struct Type{
	pair<int, int> Arr[3];
}Person[100005];
// bool Compare(Type A, Type B) {
// 	int AMax0 = max({A.Arr[0], A.Arr[1], A.Arr[2]});
// 	int BMax0 = max({B.Arr[0], B.Arr[1], B.Arr[2]});
// 	return AMax0 > BMax0;
// }
vector<int> Set[3];
bool Compare(pair<int, int> A, pair<int, int> B) {
	return A.first > B.first;
}
bool Compare2(vector<int> A, vector<int> B) {
	return A.size() > B.size();
}
bool Compare3(int A, int B) {
	return Person[A].Arr[0].first - Person[A].Arr[1].first < Person[B].Arr[0].first - Person[B].Arr[1].first;
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	for(int i = 1; i <= T; i++) {
		for(int j = 0; j < 3; j++) {
			Set[j].clear();
		}
		cin >> N;
		for(int i = 1; i <= N; i++) {
			for(int j = 0; j < 3; j++) {
				cin >> Person[i].Arr[j].first;
				Person[i].Arr[j].second = j;
			}
		}
		int Ans = 0;
		for(int i = 1; i <= N; i++) {
			sort(Person[i].Arr + 0, Person[i].Arr + 3, Compare);
			Set[Person[i].Arr[0].second].push_back(i);
			Ans += Person[i].Arr[0].first;
		}
		sort(Set + 0, Set + 3, Compare2);
		if(Set[0].size() > N / 2) {
			sort(Set[0].begin(),Set[0].end(), Compare3);
			for(int i = 0; i < Set[0].size() - N / 2; i++) {
				Ans -= Person[Set[0][i]].Arr[0].first;
				Ans += Person[Set[0][i]].Arr[1].first;
			}
		}
		cout << Ans << '\n';
	}
	return 0;
}
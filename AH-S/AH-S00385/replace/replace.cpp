//10 + bu ke yi zong si ling
#include <bits/stdc++.h>
using namespace std;
#define int long long
int N, Q;
typedef unsigned long long Hash_t;
Hash_t Hash1[2000005], Hash2[2000005], Hash3[2000005], Hash4[2000005];
Hash_t Base1 = 131, Base[2000005];
Hash_t Query(Hash_t Arr[], int L, int R) {
	if(L > R) return 0;
	return Arr[R] - Arr[L - 1] * Base[R - L + 1];
}
bool Flag[2000005];
int Size[2000005];
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> N >> Q;
	if(N <= 100) {
		Base[0] = 1;
		for(int i = 1; i <= 2000; i++) {
			Base[i] = Base[i - 1] * Base1;
		}
		for(int i = 1; i <= N; i++) {
			string Str1, Str2;
			cin >> Str1 >> Str2;
			for(char j : Str1) {
				Hash1[i] = Hash1[i] * Base1 + j;
			}
			for(char j : Str2) {
				Hash2[i] = Hash2[i] * Base1 + j;
			}
			Size[i] = Str1.size();
		}
		for(int i = 1; i <= Q; i++) {
			string Str1, Str2;
			cin >> Str1 >> Str2;
			if(Str1.size() != Str2.size()) cout << "0\n";
			else{
				for(int j = 0; j < Str1.size(); j++) {
					Hash3[j + 1] = Hash3[j] * Base1 + Str1[j];
				}
				for(int j = 0; j < Str1.size(); j++) {
					Hash4[j + 1] = Hash4[j] * Base1 + Str2[j];
				}
				int Ans = 0;
				for(int j = 1; j <= N; j++) {
					for(int k = 0, l = Size[j] - 1; l < Str1.size(); k++, l++) {
						if(Query(Hash3, 1, k + 1 - 1) == Query(Hash4, 1, k + 1 - 1) && Query(Hash3, l + 1 + 1, Str1.size()) == Query(Hash4, l + 1 + 1, Str1.size()) && Query(Hash3, k + 1, l + 1) == Hash1[j] && Query(Hash4, k + 1, l + 1) == Hash2[j]) 
							Ans++;
					}
				}
				cout << Ans << '\n';
			}
		}
	}else{
	 	for(int i = 1; i <= Q; i++) cout << "0\n";
	}
	return 0;
}
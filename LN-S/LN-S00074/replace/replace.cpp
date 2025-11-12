#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <unordered_map>

using namespace std;
typedef unsigned long long ULL;
typedef pair<ULL, ULL> PUU;

const int N = 200005, M = 5000001;
const int BASE1 = 131, BASE2 = 13331;

string s1[N], s2[N];
int n, q;
ULL p1[M + 5], p2[M + 5];
ULL t11[M + 5], t21[M + 5], t12[M + 5], t22[M + 5];
unordered_map<ULL, int> ha1, ha2;

void init() {
    p1[0] = p2[0] = 1;
    for (int i = 1; i <= M; i ++ ) p1[i] = p1[i - 1] * BASE1, p2[i] = p2[i - 1] * BASE2;
}

int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    init();

    cin >> n >> q;
    for (int i = 1; i <= n; i ++ ) {
        cin >> s1[i] >> s2[i];
        ULL s11 = 0, s12 = 0;
        for (char c : s1[i]) s11 = s11 * BASE1 + c, s12 = s12 * BASE2 + c;
        s11 = s11 * BASE1 + '&', s12 = s12 * BASE2 + '&';
        for (char c : s2[i]) s11 = s11 * BASE1 + c, s12 = s12 * BASE2 + c;
        // printf("#%llu %llu\n", s11, s12);
        ha1[s11] ++ , ha2[s12] ++ ;
    }

    for (int i = 1; i <= q; i ++ ) {
        int cnt = 0;
        string t1, t2;
        cin >> t1 >> t2;
        if (t1.size() != t2.size()) {
            cout << "0\n";
            continue;
        }
        for (int i = 0; i < t1.size(); i ++ ) t11[i] = (!i ? 0ull : t11[i - 1]) * BASE1 + t1[i], t12[i] = (!i ? 0ull : t12[i - 1]) * BASE2 + t1[i];
        for (int i = 0; i < t2.size(); i ++ ) t21[i] = (!i ? 0ull : t21[i - 1]) * BASE1 + t2[i], t22[i] = (!i ? 0ull : t22[i - 1]) * BASE2 + t2[i];
        
        int pre = 0, suf = t1.size() - 1;
        for (; pre < t1.size() && t1[pre] == t2[pre]; pre ++ );
        for (; suf >= 0 && t1[suf] == t2[suf]; suf -- );
        for (int l = pre; l >= 0; l -- )
            for (int r = suf; r < t1.size(); r ++ ) {
                int len = r - l + 1;
                ULL tt11 = t11[r] - (!l ? 0ULL : t11[l - 1]) * p1[len], tt12 = t12[r] - (!l ? 0ULL : t12[l - 1]) * p2[len];
                ULL tt21 = t21[r] - (!l ? 0ULL : t21[l - 1]) * p1[len], tt22 = t22[r] - (!l ? 0ULL : t22[l - 1]) * p2[len];
                ULL T1 = tt11 * p1[len + 1] + '&' * p1[len] + tt21, T2 = tt12 * p2[len + 1] + '&' * p2[len] + tt22;
                // printf("!%llu %llu\n", T1, T2);
                if (ha1.find(T1) != ha1.end() && ha2.find(T2) != ha2.end() && ha1[T1] == ha2[T2]) cnt += ha1[T1];
            }
        cout << cnt << '\n';
    }
    return 0;
}
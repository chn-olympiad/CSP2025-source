#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5, MAXLEN = 1e6 + 5;;

const long long der = 89, mod = 1e9 + 7;
long long mpow(long long temp, long long k) {
    long long res = 1;
    while (k) {
        if (k & 1) res = res * temp % mod;
        temp = temp * temp % mod;
        k >>= 1;
    }
    return res;
}
int n, q;
int len;
string seq1[MAXN], seq2[MAXN];
string ques1[MAXN], ques2[MAXN];

long long premul[MAXLEN];

vector<long long> seq1_hash[MAXN], seq2_hash[MAXN], ques1_hash[MAXN], ques2_hash[MAXN];
map<pair<long long, long long>, int> cnt_mp;
map<pair<long long, long long>, int> id_mp;
vector<int> id_rec[MAXN];
int mp_cnt;


int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    long long tempder = mpow(der, mod - 2);
    premul[0] = 1;
    for (int i = 1; i <= MAXLEN - 5; i++) {
        premul[i] = premul[i - 1] * der % mod;
    }
    // printf("premul[1] %lld  test %lld\n", premul[2], (premul[2] * der % mod) * der % mod);
    for (int i = 1; i <= n; i++) {
        cin >> seq1[i] >> seq2[i];
        int templen = seq1[i].size();
        len += 2 * seq1[i].size();
        int fir_pos = -1, last_pos = -1;
        for (int j = 0; j < templen; j++) {
            if (j == 0) {
                seq1_hash[i].push_back((long long)seq1[i][j]);
                seq2_hash[i].push_back((long long)seq2[i][j]);
            } else {
                seq1_hash[i].push_back((long long)(seq1_hash[i].back() * der + seq1[i][j]) % mod);
                seq2_hash[i].push_back((long long)(seq2_hash[i].back() * der + seq2[i][j]) % mod);
            }
            if (seq1[i][j] != seq2[i][j]) {
                if (fir_pos == -1) fir_pos = j;
                last_pos = j;
            }
        }
        if (fir_pos != -1) {
            long long hash1, hash2;
            if (fir_pos == 0) {
                hash1 = seq1_hash[i][last_pos];
                hash2 = seq2_hash[i][last_pos];
            } else {

                hash1 = (seq1_hash[i][last_pos] - premul[last_pos - fir_pos + 1] * seq1_hash[i][fir_pos - 1] % mod + mod) % mod;
                hash2 = (seq2_hash[i][last_pos] - premul[last_pos - fir_pos + 1] * seq2_hash[i][fir_pos - 1] % mod + mod) % mod;
            }
            // printf("fir %d last %d hash1 hash2 %lld %lld\n", fir_pos, last_pos, hash1, hash2);
            pair<long long, long long> tempp = make_pair(hash1, hash2);
            if (cnt_mp[tempp] == 0) {
                id_mp[tempp] = ++mp_cnt;
            }
            cnt_mp[tempp]++;
            id_rec[mp_cnt].push_back(i);
        }
    }
    for (int i = 1; i <= q; i++) {
        cin >> ques1[i] >> ques2[i];
        int templen = ques1[i].size();
        int fir_pos = -1, last_pos = -1;
        for (int j = 0; j < templen; j++) {
            if (j == 0) {
                ques1_hash[i].push_back((long long)ques1[i][j]);
                ques2_hash[i].push_back((long long)ques2[i][j]);
            } else {
                ques1_hash[i].push_back((long long)(ques1_hash[i].back() * der + ques1[i][j]) % mod);
                ques2_hash[i].push_back((long long)(ques2_hash[i].back() * der + ques2[i][j]) % mod);
            }
            if (ques1[i][j] != ques2[i][j]) {
                if (fir_pos == -1) fir_pos = j;
                last_pos = j;
            }
        }
        long long hash1, hash2;
        if (fir_pos == 0) {
            hash1 = ques1_hash[i][last_pos];
            hash2 = ques2_hash[i][last_pos];
        } else {
            hash1 = (ques1_hash[i][last_pos] - premul[last_pos - fir_pos + 1] * ques1_hash[i][fir_pos - 1] % mod + mod) % mod;
            hash2 = (ques2_hash[i][last_pos] - premul[last_pos - fir_pos + 1] * ques2_hash[i][fir_pos - 1] % mod + mod) % mod;
        }
        pair<long long, long long> tempp = make_pair(hash1, hash2);
        int tempans = cnt_mp[tempp];
        printf("%d\n", tempans);
    }
    return 0;
}
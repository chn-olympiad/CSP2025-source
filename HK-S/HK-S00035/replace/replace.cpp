#include <bits/stdc++.h>

using namespace std;

int fenwick[2000000 + 10];
int mx = 2000000;

int get(int k){
    int res = 0;
    while(k >= 1){
        res += fenwick[k];
        k -= k & -k;
    }
    res += fenwick[0];
    return res;
}

void add(int k, int x){
    if(k == 0){
        fenwick[0] += x;
        return;
    }
    while(k <= 2000000){
        fenwick[k] += x;
        k += k & -k;
    }
}

int main(){
    ifstream cin("replace.in");
    ofstream cout("replace.out");
    memset(fenwick, 0, sizeof(fenwick));
    int n, q;
    cin >> n >> q;
    vector<vector<int>> s;
    for(int i = 1; i <= n; i++){
        string s1;
        string s2;
        cin >> s1 >> s2;
        int sz = s1.size();
        int idx1, idx2;
        for(int j = 0; j < s1.size(); j++){
            if(s1[j] == 'b') idx1 = j;
            if(s2[j] == 'b') idx2 = j;
        }
        s.push_back({idx1 - idx2, min(idx1, idx2), sz - 1 - max(idx1, idx2), i});
    }
    vector<vector<int>> v;
    for(int i = 1; i <= q; i++){
        string s1;
        string s2;
        cin >> s1 >> s2;
        int sz = s1.size();
        int idx1, idx2;
        for(int j = 0; j < s1.size(); j++){
            if(s1[j] == 'b') idx1 = j;
            if(s2[j] == 'b') idx2 = j;
        }
        v.push_back({idx1 - idx2, min(idx1, idx2), sz - 1 - max(idx1, idx2), i});
    }
    int res[q + 1] = {0};
    sort(s.begin(), s.end());
    sort(v.begin(), v.end());
    int cur = 0;
    int pt = 0;
    while(cur < q){
        int a = v[cur][1];
        int b = v[cur][2];
        while(pt < n && s[pt][0] < v[cur][0]){
            pt++;
        }
        while(pt < n && s[pt][0] == v[cur][0] && s[pt][1] <= a){
            add(s[pt][2], 1);
            pt++;
        }
        res[v[cur][3]] = get(b);
        cur++;
        if(cur < q && v[cur - 1][0] != v[cur][0]){
            memset(fenwick, 0, sizeof(fenwick));
        }
    }
    for(int i = 1; i <= q; i++){
        cout << res[i] << '\n';
    }
    return 0;
}
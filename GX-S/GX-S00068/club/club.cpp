#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;

ull T, n;
const ull MAXN = 10e5+100;
ull a[MAXN][3];
vector<pair<ull,ull>>DP, DP2;
ull ans[MAXN];
//vector<bool>Mark;

ull getMax(ull* a){
    return max(max(a[0],a[1]),a[2]);
}

ull getMaxPos(ull* a){
    ull M = max(max(a[0],a[1]),a[2]);
    for(ull i = 0; i < 3; i++)
        if(a[i] == M)return i;
    return -1;
}

ull getMin(ull* a){
    return min(min(a[0],a[1]),a[2]);
}

ull getMax2(ull* a){
    ull Max = getMax(a);
    ull Min = getMin(a);
    ull MaxNum = 0, MinNum = 0, Else;
    for(ull i = 0; i < 3; i++){
        if(a[i] == Max)MaxNum++;
        if(a[i] == Min)MinNum++;
        if(a[i] != Max && a[i] != Min)Else = a[i];
    }
    if(MaxNum > MinNum)return Max;
    if(MaxNum < MinNum)return Min;
    return Else;
}

void init(){
    //DP.clear();
    DP2.clear();
    for(ull i = 0; i < n; i++){
        //DP.push_back({getMax(a[i]) - getMin(a[i]), i});
        DP2.push_back({getMax(a[i]), i});
    }
    //sort(DP.begin(), DP.end());
    sort(DP2.begin(), DP2.end(), greater<pair<ull,ull>>());
}

void init2(ull pos){
    DP.clear();
    for(ull i = 0; i < n; i++){
        if(pos == getMaxPos(a[i])){
            DP.push_back({getMax(a[i]) - getMax2(a[i]), i});
            //cout << "D2:"<< i << ' ' << getMax(a[i]) << ' ' << getMax2(a[i]) << '\n';
        }
    }
    sort(DP.begin(), DP.end(), greater<pair<ull,ull>>());
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> T;
    while(T --> 0){
        cin >> n;
        for(ull i = 0; i < n; i++){
            cin >> a[i][0] >> a[i][1] >> a[i][2];
        }
        init();
        ull cnt[3] = {};
        //Mark.clear();
        //Mark.resize(n);
        ans[n] = 0;
        for(auto i : DP2){
            ull pos = getMaxPos(a[i.second]);
            cnt[pos]++;
            ans[n] += i.first;
        }
        //cout << "Deb" << ans[n] << " cnt:";
        //for(ull i = 0; i < 3; i++){
            //cout << cnt[i] << ' ';
        //}
        //cout << '\n';
        ull needCarry = getMaxPos(cnt);
        init2(needCarry);
        //cout << "D:" << cnt[needCarry] - n / 2 << '\n';
        ull now = n;
        if(cnt[needCarry] > n / 2)
        for(ull i = n - 1, j = cnt[needCarry] - n / 2; i >= n / 2 && j != -1; i--, j--){
            ans[i] = ans[i + 1] - DP.back().first;
            DP.pop_back();
            now--;
        }
        cout << ans[now] << '\n';
    }
    return 0;
}

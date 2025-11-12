#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
struct Student{
    int score, id;
}s[maxn];

bool cmp(Student x, Student y){
    return x.score > y.score;
}

int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin>>n>>m;
    for(int i = 1;i <= n * m;++i){
        cin>>s[i].score;
        s[i].id = i;
    }
    sort(s + 1, s + n * m + 1, cmp);
    for(int i = 1;i <= m;++i){
        for(int j = 1;j <= n;++j){
            int idx = j;
            if(i % 2 == 0)  idx = n - j + 1;
            if(s[n * (i - 1) + j].id == 1){
                cout<<i<<" "<<idx<<'\n';
                return 0;
            }
        }
    }
    return 0;
}

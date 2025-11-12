#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 100+5;
int score[N];
int main(){
    freopen( "seat.in" , "r" , stdin);
    freopen( "seat.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    int student = n * m;
    int R;
    cin >> R;
    score[R] = 1;
    for(int i = 2; i <= student; ++i){
        int tmp;
        cin >> tmp;
        score[tmp] = 1;
    }
    int cnt = 0;
    for(int i = 100; i >= R; --i){
        if(score[i]){
            cnt++;
        }
    }
    int c = ceil((float) (cnt) / (float) (n));
    int r;
    if(c % 2 == 0){
        r = (n + 1) - (cnt % n);
    } else {
        r = cnt % n;
    }
    if(cnt % n == 0){
        r = n;
    }
    cout << c << ' ' << r << endl;
    return 0;

}

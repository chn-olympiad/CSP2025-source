#include<bits/stdc++.h>
#define rep(i,a,b,c) for(int i=(a);i<=(b);i+=(c))
#define per(i,a,b,c) for(int i=(a);i>=(b);i-=(c))
#define ALL(a) (a).begin(),(a).end()
using namespace std;
using ll = long long;

const int INF = INT_MAX / 2;
const int N = 15;

int n, m;
int s[N];
int a[N][N];

int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    cin >> n >> m;
    int k = n * m;
    rep(i,1,k,1) cin >> s[i];
    int howToDo = s[1];
    sort(s + 1, s + k + 1,greater<int>());
    int cnt = 0;
    rep(i,1,n,1){
        if((i % 2))
            rep(j,1,m,1) a[j][i] = s[++cnt];
        else
            per(j,m,1,1) a[j][i] = s[++cnt];
    }
    rep(i,1,n,1) rep(j,1,m,1) if(a[i][j] == howToDo){
        cout << j <<' ' << i;
        return 0;
    }
    return 0;
}

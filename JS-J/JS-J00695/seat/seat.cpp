//long long memory time
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int N = 200007;
long long n, m, score[N];
long long Sco, No;
long long c, r;

bool cmp(long long a, long long b){
    return a > b;
}

int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n * m; i++) cin >> score[i];
    Sco = score[1];
    sort(score + 1, score + 1 + n * m, cmp);
    for(int i = 1; i <= n * m; i++) if(score[i] == Sco) No = i;
    //cout << "No:" << No << endl;
    long long zu = 2 * n;
    //cout << "zu:" << zu << endl;
    long long frontzu = No / zu;
    //cout << "frontzu:" << frontzu << endl;
    long long reczu = frontzu + 1;
    //cout << "reczu:" << reczu << endl;
    long long Nozu = No - frontzu * zu;
    //cout << "Nozu:" << Nozu << endl;
    if(Nozu <= frontzu * zu + n) {
        r = Nozu; c = frontzu * 2 + 1;
    }
    else if(Nozu > frontzu * zu + n){
        Nozu -= n;
        r = n - Nozu + 1; c = frontzu * 2 + 2;
    }
    cout << c << " " << r;
    return 0;
}

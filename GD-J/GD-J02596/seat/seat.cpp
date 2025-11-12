#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    ll n,m;
    cin>>n>>m;

    vector<int> scores;

    ll seatcut = n*m;
    for (ll i = 0; i<seatcut; i++) {
        ll score;
        cin >> score;
        scores.push_back(score);
    }
    ll smallr = scores[0];
    sort(scores.begin(), scores.end());
    reverse(scores.begin(), scores.end());

    ll target = -1;
    for (ll i=0; i<seatcut; i++) {
        if (scores[i]==smallr) {
            target=i;
            break;
        }
    }

    ll r1 = target/n+1;
    ll r2 = (target%n)+1;
    if (r1%2==0) r2 = n+1-r2;
    cout << r1 << " "<< r2 << endl;
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}


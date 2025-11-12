#include <bits/stdc++.h>
#define IOFILE "club"
#define isfull( __club__ ) ( __club__ >= (n / 2) )
#define ARR_MAX 114514

using namespace std;

long long t;

long long n;
long long good[ARR_MAX][4]; // good rate i for j
long long club[4]; // persons number of club

int main() {
    freopen(IOFILE".in", "r", stdin);
    freopen(IOFILE".out", "w", stdout);

    cin >> t;
    while(t--) {
        cin >> n;
        for (long long j = 1; j <= n; j++) {
            cin >> good[j][1] >> good[j][2] >> good[j][3];
        }

        long long sum = 0;
        for (long long i = 1; i <= n; i++) {
            if (club[1] < n / 2 && 
            max(good[i][1], good[i][2]) == good[i][1] && 
            max(good[i][1], good[i][3]) == good[i][1]) { // c1 is max
                sum += good[i][1];
                club[1]++;
            } else if (club[2] < n / 2 && 
            max(good[i][1], good[i][2]) == good[i][2] && 
            max(good[i][2], good[i][3]) == good[i][2]) { // c2 is max
                sum += good[i][2];
                club[2]++;
            } else if (club[3] < n / 2 ) { // c3 is max
                sum += good[i][3];
                club[3]++;
            } else if (club[1] < n / 2 && 
            max(good[i][1], good[i][2]) == good[i][1] && 
            max(good[i][1], good[i][3]) == good[i][1]) { // c3 is full, c1 is max
                sum += good[i][1];
                club[1]++;
            } else { // c1 is full
                sum += good[i][2];
                club[2]++;
            }
        }
        cout << sum << endl;
    }

    return 0;
}
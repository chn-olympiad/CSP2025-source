#include <bits/stdc++.h>
#define IOFILE "road"
#define ARR_MAX 1000010
#define to_counrty( __j__ ) ( __j__ + city + 1 )


using namespace std;

struct Road {
    long long city1, city2;
    long long w;
};

long long city, road, country; // * number // m, n, k
long long roads[ARR_MAX];
long long otoi[ARR_MAX]; // country [change] to city
long long otoiw[ARR_MAX]; // weight of country to city 


long long ans;

int main() {
    freopen(IOFILE".in", "r", stdin);
    freopen(IOFILE".out", "w", stdout);

    cin >> city >> road >> country;
    for (long long i = 1; i <= road; i++) {
        cin >> ans;
    }

    for (long long j = 1; j <= country; j++) {
        cin >> otoi[j];
        for (long long a = 1; a <= city; a++) {
            cin >> ans;
        }
    }
    while (true) {
        cout << "\0";
    }




    return 0;
}
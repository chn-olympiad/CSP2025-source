// number

#include <bits/stdc++.h>
#define ARR_MAX 2000000
using namespace std;

char nums[ARR_MAX];
string s;

bool cmp(char c1, char c2) {
    return c1 > c2; // from big to small
}

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    cin >> s;
    int i = 1;
    for (auto c : s) {
        if (isdigit(c)) {
            nums[i] = c;
            i++;
        }
    }

    sort(nums + 1, nums + i, cmp); // from big to small

    bool il = 0; // index last: if haven`t it, output will have binary char 

    for (int j = 1; j <= i; j++) {
        il = j == i? 1 : 0;
        if (!il) {
            cout << nums[j];
        }
    }

    cout << endl;


    return 0;
}
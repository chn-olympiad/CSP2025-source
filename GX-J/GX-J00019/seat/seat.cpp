// seat

#include <bits/stdc++.h>
#define ARR_MAX 200
#define int long long

using namespace std;

int row, col; // n, m
int marks[ARR_MAX * ARR_MAX];
int mp[ARR_MAX][ARR_MAX];
int ming; // xiao ming 

bool cmp(int n1, int n2) {
    return n1 > n2;
}


signed main() {

    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    cin >> row >> col;

    for (int i = 1; i <= row * col; i++) {
        cin >> marks[i];
    }
    ming = marks[1];

    sort(marks + 1, marks + (row * col + 1), cmp);


    bool fl = true; 
    int index = 1;
    for (int i = 1; i <= row; i++) {
        if (fl) { // from up to down;
            for (int j = 1; j <= col; j++) {
                if (marks[index] == ming) {
                    cout << i << ' ' << j << endl;
                    return 0;
                }
                index++;
            }
        } else { // from down to up;
            for (int j = col; j >= 1; j--) {
                if (marks[index] == ming) {
                    cout << i << ' ' << j << endl;
                    return 0;
                }
                index++;
            }
        }
        fl = !fl; // turn flag;
    }

    

    return 0;
}
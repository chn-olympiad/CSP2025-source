#include <bits/stdc++.h>
using namespace std;
const int kMax = 100005;
int t;
struct Node{
    int myd;
    int bh;
};
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while (t--) {
        int n;
        int sum = 0;
        Node a[kMax][3+1];
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 3; j++) {
                cin >> a[i][j].myd;
                a[i][j].bh = j;
            }
        }
        Node my_max[kMax];
        int club1 = 0, club2 = 0, club3 = 0;
        for (int i = 1; i <= n; i++) {
            if(a[i][1].myd > a[i][2].myd && a[i][2].myd > a[i][3].myd) my_max[i].bh = 1, my_max[i].myd = a[i][1].myd;
            else if(a[i][1].myd >= a[i][3].myd && a[i][3].myd >= a[i][2].myd) my_max[i].bh = 1, my_max[i].myd = a[i][1].myd;
            else if(a[i][2].myd >= a[i][1].myd && a[i][1].myd >= a[i][3].myd) my_max[i].bh = 2, my_max[i].myd = a[i][2].myd;
            else if(a[i][2].myd >= a[i][3].myd && a[i][3].myd >= a[i][1].myd) my_max[i].bh = 2, my_max[i].myd = a[i][2].myd;
            else if(a[i][3].myd >= a[i][1].myd && a[i][1].myd >= a[i][2].myd) my_max[i].bh = 3, my_max[i].myd = a[i][3].myd;
            else if(a[i][3].myd >= a[i][2].myd && a[i][2].myd >= a[i][1].myd) my_max[i].bh = 3, my_max[i].myd = a[i][3].myd;
            //cout << my_max[i].bh << " " << my_max[i].myd << endl;
        }
        for (int i = 1; i <= n; i++) {
            if (club1 < n / 2 && my_max[i].bh == 1) club1++, sum += my_max[i].myd/*,cout << sum << "AAA"*/;
            if (club2 < n / 2 && my_max[i].bh == 2) club2++, sum += my_max[i].myd/*,cout << sum << "BBB"*/;
            if (club3 < n / 2 && my_max[i].bh == 3) club3++, sum += my_max[i].myd/*,cout << sum << "CCC"*/;
        }
        cout << sum;

    }



    return 0;
}

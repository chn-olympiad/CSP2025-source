#include <bits/stdc++.h>

using namespace std;

struct node{
    int one, two, three;
};

const int MAXN = 1e5+5;
node a[MAXN];
bool tmp = true;

bool cmp(node x, node y){
    return x.one > y.one;
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        long long sum = 0;
        tmp = true;
        for(int i = 1; i <= n; i++){
            cin >> a[i].one >> a[i].two >> a[i].three;
            if(a[i].three != 0){
                tmp = false;
            }

        }
        if(n == 2){
            cout << max((a[1].one + a[2].two), max((a[1].one + a[2].three), max((a[1].two + a[2].one), max((a[1].two + a[2].three), max((a[1].three, a[2].one), (a[1].three + a[2].two)))))) << endl;
        }else if(tmp){
            sort(a + 1, a + n + 1, cmp);
            for(int i = 1; i <= n / 2; i++){
                sum += a[i].one;
            }
            cout << sum << endl;
        }else{
            for(int i = 1; i <= n; i++){
                sum += max(a[i].one, max(a[i].two, a[i].three));
            }
            cout << sum <<endl;
        }
    }
    return 0;
}

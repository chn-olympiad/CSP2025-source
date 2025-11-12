#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        int satisfy[n][3];
        int max1[n], max2[n], diff[n];
        for (int i = 0; i < n; i++){
            cin >> satisfy[i][0] >> satisfy[i][1] >> satisfy[i][2];
            if (satisfy[i][0] > satisfy[i][1]){
                max1[i] = satisfy[i][0];
                max2[i] = satisfy[i][1];

            }
            else {
                max1[i] = satisfy[i][1];
                max2[i] = satisfy[i][0];
            }
            if (satisfy[i][2] > max1[i]){
                max2[i] = max1[i];
                max1[i] = satisfy[i][2];
            }
            else if (satisfy[i][2] > max2[i]){
                max2[i] = satisfy[i][2];
            }
            diff[i] = max1[i] - max2[i];

        }


        int s = 0, na = 0, nb = 0, nc = 0;
        vector<int> a;
        vector<int> b;
        vector<int> c;

        for (int i = 0; i < n; i++){
                s += max1[i];
            if (satisfy[i][0] == max1[i]){
                na++;
                a.push_back(diff[i]);
                continue;
            }
            if (satisfy[i][1] == max1[i]){
                nb++;
                b.push_back(diff[i]);
                continue;
            }
            if (satisfy[i][2] == max1[i]){
                nc++;
                c.push_back(diff[i]);
                continue;
            }




        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());

        if (na > n/2){
            int remove = na - n/2;

            for (int i = 0; i < remove; i++){
                s -= a[i];
            }
        }
        else if (nb > n/2){
            int remove = nb - n/2;

            for (int i = 0; i < remove; i++){
                s -= b[i];
            }
        }
        else if (nc > n/2){
            int remove = nc - n/2;

            for (int i = 0; i < remove; i++){
                s -= c[i];
            }
        }
        cout << s << endl;

    }
    return 0;
}


#include "bits/stdc++.h"

using namespace std;

int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<int> f;

    for (int i=0; i<n*m; i++){
        int num;
        cin >> num;
        f.push_back(num);
    }
    int p = f[0];
    sort(f.begin(), f.end());

    for (int i=m*n-1;i>=0;i--){
        if (f[i] == p){
            int n1=i+1;
            int count = 1;

            int c=1, r=1; 


            bool flag = 0; // true up, flase down
            while (count <= n1){
                if (r < n && flag == 0 && r !=1){
                    r++;
                }else if (r < n && flag == 1 && r !=1){
                    r--;
                }else if (r = n || r == 1){
                    if (flag == 1){
                        flag = 0;
                        c++;
                        r++;
                        count++;
                    }else{
                        flag = 1;
                        c++;
                        r--;
                        count++;
                    }
                }
                count++;
            }
            cout << c << " " << r << endl;
        }
    }

    return 0;
}
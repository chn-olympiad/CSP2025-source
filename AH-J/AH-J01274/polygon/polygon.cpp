#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    int n = 5, result=0;
    int tranch[n] = {1,2,3,4,5};

    for (int i = 3; i < n+1; i++) { // everthing select count of tranch
        int left=0, right=0;
        for (int j = 0; j < i; j++) { // everthing wide
            left = j;
            right = left + i - 1;
            int son[i];

            // if (left > n-i) break;
            result ++;
            for (int k = 0; k < right - left+1; k ++) {
                son[k] = tranch[left + k];
                cout << son[k] << " ";
            }
            left ++;
            cout << endl;
        }
    }
    cout << result;
    fclose(stdin);
    fclose(stdout);
    return 0;
}


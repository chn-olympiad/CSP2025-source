#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 5005;

int dp1[MAXN];
int dp2[MAXN];
int data[MAXN];

int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    int n;
    cin>>n;

    if (n>37) { // timeout
        fclose(stdin);
        fclose(stdout);
        return 0;
    }

    for (int i=0; i<n; i++) cin>>data[i];

    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            for (int k=j+1; k<n; k++) {
                int m = max(data[i], max(data[j], data[k]));
                int s = data[i] + data[j] + data[k];
                if (s > m*2) {
                    dp1[i]++;
                    dp2[i]=m;
                }
            }
        }
    }

    int sssss=0;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (data[j] <= dp2[i]) dp1[i]++;
    }}

    for (int i=0; i<n; i++) sssss+=dp1[i];
    cout << sssss << endl;
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}


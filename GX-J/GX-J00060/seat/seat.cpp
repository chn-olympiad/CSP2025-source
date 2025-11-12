#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    string s[n*m];
    for(int i=0; i<m*n; i++){
        cin >> s;
    }
    int zhi = s[0] -'0';
    int xia=0;
    sort(s.begin(), s.end());
    for(int i=0; i<n*m; i++){
        if(s[i]-'0' == zhi){
            xia = i+1;
        }
    }
    int n1, m1;
    if(m%2!=0){
        m1 = xia/n;
        n1 = xia%n;
    }else{
        m1 = n-xia/n;
        n1 = n-xia%n;
    }

    cout << n1 <<" " << m1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

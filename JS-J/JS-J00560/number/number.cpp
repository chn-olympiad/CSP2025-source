#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;

    long long q[11];
    for (int i = 0;i <= 9;i++) q[i] = 0;
    cin >> a;
    int h = 0;
    for (int i = 0;i < a.size();i++){
        if (int(a[i] - '0') >= 0 && int(a[i] - '0') <= 9){
            q[a[i] - '0'] ++;
        }
    }

    for (int i = 9;i >= 0;i--){
        for (int j = 0;j < q[i];j++){
            cout << i;
        }
    }
    return 0;
}

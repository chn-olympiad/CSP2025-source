#include <bits/stdc++.h>
using namespace std;
int n,m;
string a;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int num = 0,x = 1;
    cin >> n >> m;
    cin >> a;
    for (int i = 0;i <= a.length();i++){
        if (a[i] == '1'){
            num++;
        }
    }
    for (int i = 1;i < num;i++){
        x = x * 2;
    }
    cout << x;
}

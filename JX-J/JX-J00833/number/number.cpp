#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
int b[N];
int main()
{
    freopen("number.in" , "r" , stdin);
    freopen("number.out" , "w" , stdout);
    string a;
    cin >> a;
    int j = 0;
    for(int i = 0;i < a.size();++i){
        if(a[i] - '0' >= 0 && a[i] - '0' < 10){
            b[j] = (int)a[i] - '0';
            ++j;
        }
    }
    sort(b , b + j);
    for(int i = j - 1;i >= 0;--i){
        cout << b[i];
    }
    return 0;
}


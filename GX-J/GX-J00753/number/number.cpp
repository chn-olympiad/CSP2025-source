#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e6 + 5;
string s;
int a[15] = {0};

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for (size_t i = 0;i < s.size();i++){
        if (s[i] >= '0' && s[i] <= '9'){
            a[int(s[i] - '0')]++;
        }
    }
    for (int i = 9;i >= 0;i--){
        for (int j = 1;j <= a[i];j++){
            cout << i;
        }
    }
    return 0;
}
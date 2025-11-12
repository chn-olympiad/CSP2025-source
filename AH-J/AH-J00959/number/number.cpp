#include <bits/stdc++.h>
using namespace std;
string s;
int a[10] = {0};
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for(int i = 0; i < int(s.size()); ++ i)
        if(s[i] >= '0' and s[i] <= '9')a[s[i] - '0'] ++;
    bool flag = 1;
    for(int i = 9; i >= 0; -- i){
        if(a[i] != 0)flag = 0;
        if(i == 0 and flag)cout <<0;
        else{
            for(int j = 1; j <= a[i]; ++ j)
                cout << i;
        }
    }
    return 0;
}

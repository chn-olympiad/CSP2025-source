#include<bits/stdc++.h>
using namespace std;
string str;
int num[1000005], t;
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    getline(cin, str);
    int len = str.length();
    for(int i = 0; i < len; i ++)
        if(str[i] - '0' >= 0 && str[i] - '0' <= 9) num[++ t] = str[i] - '0';
    sort(num + 1, num + 1 + t);
    for(int i = t; i >= 1; i --) cout << num[i];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
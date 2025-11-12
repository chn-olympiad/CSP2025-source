#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s, a;
    long long b;
    vector <long long> v;
    cin >> s;
    for(long long i=9; i>=0; i--){
        for(long long j=0; j<s.size(); j++){
            if(s[j] - '0' == i){
                cout << i;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

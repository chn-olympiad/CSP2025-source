#include<bits/stdc++.h>
using namespace std;
string s;
char a[10];
int main(){
    freopen("number.in", "r",stdin);
    freopen("number.out", "w",stdout);
    cin >> s;
    int len = s.size();
    for(int i = 0;i < len;i++){
        if(s[i] >= '0' && s[i] <= '9') a[s[i]]++;
    }
    for(int i = 57;i >= 48;i--){
        while(a[i]--){
            cout << i - 48;
        }
    }
    return 0;
}

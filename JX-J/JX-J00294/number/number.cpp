#include<bits/stdc++.h>
using namespace std;
int main(){
    freoepen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    int a[200] = {};
    for(int i = 0; i < s.size(); i++){
        if(s[i] <= '9' and s[i] >= '0'){
            a[s[i]]++;
        }
    }
    for(int i = '9'; i >= '0'; i--){
        while(a[i]--){
            cout << char(i);
        }
    }
return 0;
}

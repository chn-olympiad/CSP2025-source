#include <bits/stdc++.h>
using namespace std;
string s,a;
int flag,maxn=9;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            a += s[i];
        }
    }
    for(int i=0;i<=10;i++){
        for(int j=0;j<=a.size();j++){
            if(a[j]==maxn){
                cout << a[j];
            }
        }
        maxn--;
    }
    return 0;
}

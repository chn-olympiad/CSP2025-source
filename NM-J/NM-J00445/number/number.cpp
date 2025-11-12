#include<bits/stdc++.h>
const int maxn = 1000005;
int b[maxn];
using namespace std;
int cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    int sz = 0,x=0;
    for(int i = 0;i<=s.size();i++){
        if(s[i] >= '0' && s[i] <= '9'){
            b[x] = s[i] - '0';
            sz++;
            x++;
        }
    }
    sort(b,b+sz,cmp);
    for(int i = 0;i<sz;i++){
        cout << b[i];
    }
    return 0;
}

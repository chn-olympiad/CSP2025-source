#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int a[1000009];
    int q=0;
    cin >> s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            a[q++]=(s[i]-'0');
        }
    }
    sort(a+0,a+q,cmp);
    for(int i=0;i<q;i++){
        cout << a[i];
    }
    return 0;
}

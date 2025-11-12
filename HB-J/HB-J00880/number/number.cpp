#include <bits/stdc++.h>
using namespace std;
string s;
int cur = 1;
const int N = 1e6+5;
int a[N];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for(int i = 0;i < s.size();i++){
        if(s[i] >= '0' && s[i] <= '9'){
            a[cur] = s[i] - '0';
            cur++;
        }
    }
    sort(a+1,a+cur,cmp);
    for(int i = 1;i < cur;i++){
        cout << a[i];
    }
    return 0;
}

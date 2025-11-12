#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;

string s;
int v[maxn];

bool cmp(int a, int b){
    return a > b;
}

int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin>>s;
    int l = s.size();
    int p = 1;
    for(int i=0;i<l;i++){
        if(s[i] - '0' >= 0 && s[i] - '0' <= 9){
            v[p] = (int)(s[i]-'0');
            p++;
        }
    }
    int le = p-1;
    sort(v+1, v+le, cmp);
    for(int i=1;i<=le;i++) printf("%d", v[i]);

    return 0;
}

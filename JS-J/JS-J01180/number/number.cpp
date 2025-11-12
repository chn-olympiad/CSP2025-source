#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
string s;
int cnt=0, a[maxn];
bool cmp(int a, int b){
    return a>b;
}
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin>>s;
    for(int i=0; i<s.size(); i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[cnt]=s[i]-'0';
            cnt++;
        }
    }
    if(cnt==1){
        cout<<a[0];
        return 0;
    }
    else{
        sort(a, a+cnt, cmp);
        for(int i=0; i<cnt; i++){
            cout<<a[i];
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int cnt,a[N];
int main (){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            cnt++;
            a[cnt]=s[i]-'0';
        }
    }
    sort(a+1,a+cnt+1,greater<int>());
    for(int i=1;i<=cnt;i++){
        cout<<a[i];
    }
    return 0;
}

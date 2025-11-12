#include <bits/stdc++.h>
using namespace std;
long long a[1000005],n,b;
string s;
int main(){
    freopen("number.in","w",stdin);
    freopen("number.out","r",stdout);
    cin >> s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            a[i+1]=s[i]-'0';
            n++;
        }
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        cout << a[i];
    }
    return 0;
}

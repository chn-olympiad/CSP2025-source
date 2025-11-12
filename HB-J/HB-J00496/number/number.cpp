#include <bits/stdc++.h>
#include <string>
using namespace std;
string s;
int a[1000005];
int cnt;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for  (int i=0;i<s.size();i++){
        if (iswdigit(s[i])){
            a[++cnt]=s[i]-'0';
        }
    }
    sort(a+1,a+cnt+1);
    for (int i=cnt;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}

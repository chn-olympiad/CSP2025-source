#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    long long len=0;
    string s;
    cin >> s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            len++;
            a[len]=s[i]-'0';
        }
    }
    sort(a+1,a+len+1);
    for(int i=len;i>=1;i--){
        cout << a[i];
    }
    return 0;
}

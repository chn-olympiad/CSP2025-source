#include <bits/stdc++.h>
using namespace std;
string s;
int a[60];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for (int i=0;i<s.size();i++){
        if ((int)s[i]<=(int)('9') && (int)s[i]>=(int)('0')){
            a[(int)s[i]]++;
        }
    }
    if (a[57]==0 && a[56]==0 && a[55]==0 && a[54]==0 && a[53]==0 && a[52]==0 && a[51]==0 && a[50]==0 && a[49]==0){
        cout<<0;
        return 0;
    }
    for (int i=57;i>47;i--){
        for (int j=0;j<a[i];j++)
            cout<<(char)i;
    }
    return 0;
}

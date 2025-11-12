#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    char s;
    int aa[1000005],index=0;
    cin>>a;
    for(int i=0;i<=a.size();i++){
        s=a[i];
        if(int(s) >=48 and int(s)<=57)aa[index++] = s-'0';

    }
    sort(aa,aa+index,greater<int>());
    for(int i=0;i<index;i++){
        cout<<aa[i];
    }
    return 0;
}

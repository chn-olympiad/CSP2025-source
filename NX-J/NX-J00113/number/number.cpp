#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char a;
    cin>>a;
    for(int i;i<a.size();i++){
        a[i]=sort(a[i],a[i+1]);
    }
    cout<<a;

    return 0;
}

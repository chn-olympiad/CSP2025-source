#include <iostream>
using namespace std;
int a[999999],s,b,c;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>s>>c;
    for(int i=0;i<s;i++){
        cin>>a[i];
        b=max(a[i],b);
    }

    cout<<b-a[1];
    return 0;
}

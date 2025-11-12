#include <iostream>
using namespace std;
int a[999999],s,b,c;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>s;
    for(int i=0;i<s;i++){
        cin>>a[i];
        b=b+a[i];
    }

    cout<<b/3+1;
    return 0;
}

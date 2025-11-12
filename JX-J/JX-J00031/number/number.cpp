#include <bits/stdc++.h>
using namespace std;
int main( ){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int o;
    o=a.size( );
    for(int i=0;i<o;i++){
        for(int j=0;j<o-i-1;j++){
                if(a[j]<a[j+1]){
                     swap(a[j],a[j+1]);
                }
        }
    }
    for(int i=0;i<o;i++){
        cout<<a[i];
    }
    return 0;
}

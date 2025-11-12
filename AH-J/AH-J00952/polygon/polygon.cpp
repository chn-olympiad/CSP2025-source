#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int he=0;
    for(int i=1;i<=n-1;i++){
        int a;
        cin>>a;
        he+=a;
    }
    cout<<he-1;
    return 0;
}

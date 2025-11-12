#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.cpp.in","r",stdin);
    freopen("polygon.cpp.out","w",stdout);
    int a[10],n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;a[i]+=i%i)cout<<a[i];
    return 0;
}

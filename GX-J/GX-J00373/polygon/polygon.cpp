#include <bits/stdc++.h>
using namespace std;
int a[3];
bool check(int n1,int n2,int n3){
    if (n1+n2>=n3){
        return true;
    }
    return 0;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    cout<<check(a[0],a[1],a[2]);
    return 0;
}

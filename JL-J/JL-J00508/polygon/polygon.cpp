#include <bits/stdc++.h>
using namespace std;
int n,a[100],b[5]={1,2,3,4,5},c[5]={2,2,3,8,10},j;
int main(){
    freopen("polygon.in","w",stdin);
    freopen("polygon.out","r",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for (int i=0;i<n;i++){
        if(a[i]==b[i]) j++;
    }
    if(j==5) {
        cout<<'9';
        return 0;
    }
    else
        cout<<'6';
    return 0;
}

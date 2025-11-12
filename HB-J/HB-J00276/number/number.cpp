#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char a[3];
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for(int i=1;i<=2;i++){
        cin>>a[i];
    }
    if(a[1]<a[2]){
        cout<<a[2]<<a[1];
        return 0;
    }
    cout<<a[1];
    return 0;
}

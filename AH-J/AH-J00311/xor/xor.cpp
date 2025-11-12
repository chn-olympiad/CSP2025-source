#include<bits/stdc++.h>
using namespace std;
int a[6];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int o=0;
    int y=0;
    int x=0;
    if(a[2]+a[1]>a[3]){
        o=1;
    }
    if(a[2]+a[3]>a[1]){
        y=1;
    }
    if(a[3]+a[1]>a[2]){
        x=1;
    }
    if(x!=0 and y!=0 and o!=0){
        cout<<x+y+o;
    }
    return 0;
}

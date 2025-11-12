#include<bits/stdc++.h>
using namespace std;
int a,b;
int c[100005];
int main(){
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
    cin>>a>>b;
    for(int i=0;i<a*b;i++){
       cin>>c[i];
    }
    cout<<a<<b;
    return 0;
}

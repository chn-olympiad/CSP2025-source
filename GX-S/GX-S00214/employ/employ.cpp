#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,z=1;
    cin>>n;
    for(int i=1;i<=n;i++){
        z=z*i;
    }
    cout<<z;
}

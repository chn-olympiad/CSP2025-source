#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int a,b,e=0;
    cin>>a>>b;
    int c[a];
    for(int i=0;i<a;i++) {
        cin>>c[i];
        if(c[i]==b) e++;
    }
    cout<<e;
    return 0;
}

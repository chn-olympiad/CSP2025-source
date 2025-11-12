#include<bits/stdc++.h>
using namespace std;
int a,b,c[100010],d,f[100010],l[100010],p=1;
int main(){
    //freopen("xor.cpp.in","r",stdin);
    //freopen("xor.cpp.out","w",stdout);
    f[1]=1;
    l[1]=1;
    cin>>a>>b;
    for(int i=1;i<=a*b;i++){
        cin>>c[i];
    }
    a=c[1];
    sort(c+2,c+a+b);

    return 0;
}

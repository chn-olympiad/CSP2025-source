#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int a,s=0,d,f,g=0;
    cin>>f>>d;
    for(int i=1;i<=f;i++){
        cin>>a;
        if(a==1)  ++s;
        else  ++g;
    }
    if(d==1)  cout<<s;
    else  cout<<g+(s/2);
    return 0;
}

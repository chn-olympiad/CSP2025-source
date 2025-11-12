#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("employ.in","r",std.in);
    freopen("employ.out","w",std.out);
    int t,n,a,h[1000],r=1,s=1,f=0;
    cin>>t>>n;
    cin>>a;
    for(int i=0;i<t;i++){
        cin>>h[i];
    }
    while(a>=0){
        if(a/10==1&&f!=n){
            r*=s;
            s++;
            f++;
        }
        else if(f==n){
            break;
        }
        a%=10;
    }
    cout<<r;
    return 0;
}

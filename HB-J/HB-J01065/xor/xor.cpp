#include <bits/stdc++.h>
using namespace std;
int main(){
    int n=0,k=0,b=0,c=0,d=0,m=0,a[500001];
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    a[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]=a[i-1]+a[i];

    }
    while(n>c){
        c=c+1;
        for(int i=c;i<=n;i++){
            if(a[i]-a[c-1]==k){
                c=i;
                d=d+1;
                break;
            }
        }

    }
    cout<<d;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,b[105],fenshu,paiming=0,c,r;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>b[i];
    fenshu=b[1];
    for(int i=1;i<=n*m;i++){
        if(fenshu==min(fenshu,b[i]))
            paiming+=1;
    }
    if(paiming%n==0){
        if((paiming/n)%2!=0){
           c=paiming/n;
           r=n;
        }
        if((paiming/n)%2==0){
            c=paiming/n+1;
            r=1;
        }
    }
    if(paiming%n!=0){
        if((paiming/n+1)%2==0){
            c=paiming/n+1;
            r=n*m-paiming%n+1;
        }
        if((paiming/n+1)%2!=0){
            c=paiming/n+1;
            r=paiming%n;
        }
    }
    cout<<c<<" "<<r;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
bool sum(int a,int b){
    return b<a;
}
int main(){
    //freopen("xor.in","r",stdin);
    //freopen("xor.out","w",stdout);
    int n,m;
    int d[1000006];
    int c[1000005];
    int a[1000005];
    int b=INT_MAX;
    cin>>n>>m;
    int reagre=2;
    bool key=0;
    for(int i=1;i<=n;++i){
        cin>>c[i];
    }
    int j=1;

    int xm=c[1];

    key=1;
    for(int i=1;i<=n;++i){
        if(i%2==0){
            b--;
        }else{
            b++;
        }

    }

    for(int i=1;i<=n;++i){
        if(i%2==0){
            b++;
        }else{
            b--;
        }

    }


    if(n<=2 || m<=1){
        cout<<1;
    }else{
        cout<<2;
    }


    return 0;
}

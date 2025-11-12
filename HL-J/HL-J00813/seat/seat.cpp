#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[105];
    bool f=0;
    int da=0;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(f){
            if(a[i]>a[1]){
                da++;
            }
        }
        f=1;
    }
    int r=a[1];
    int rm,rn;
    da++;
    rm=da/n;
    if(da%n==0){
        if(rm%2==0){
            rn=1;
        }
        else{
            rn=n;
        }
    }
    else{
        rm++;
        if(rm%2==0){
            rn=n-da%n+1;
        }
        else{
            rn=da%n;
        }
    }
    cout<<rm<<" "<<rn;
    return 0;
}

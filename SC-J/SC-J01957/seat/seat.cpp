#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int s1,sn;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    int x=n*m,r=1;
    scanf("%d",&s1);
    for(int i=2;i<=x;i++){
        scanf("%d",&sn);
        if(sn>s1) r++;
    }
    int h,l;
    if(r%n) l=r/n+1;
    else l=r/n;
    if(l%2){
        h=r%n;
        if(h==0) h=n;
    }
    else{
        h=n-r%n+1;
        if(h==n+1) h=1;
    }
    cout<<l<<" "<<h;
    return 0;
}
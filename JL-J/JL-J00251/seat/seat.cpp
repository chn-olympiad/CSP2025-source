#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a,b,d,p=0,f=0,l,k=1,u=0;
    cin>>a>>b;
    int c[a*b+1]={0};
    for(int i=1;i<=a*b;i++){
        cin>>c[i];
        d=c[1];
        l=i;
    }
    sort(c+1,c+l+1);
    for(int i=a*b;i>=1;i--){
        if(c[i]=d)p=i;
    }
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(p==f)cout<<i<<" "<<j;
            f++;
        }

    }
    return 0;
}

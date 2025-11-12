#include<bits/stdc++.h>
using namespace std;
int T,n,a[10005],b[10005],c[10005],a1,a2,b1,b2,maxi;
int main(){
    freopen("club.in","r",stdin);
    freopen("club,out","w",stdout);
    cin>>T;
    for(int t=1;t<=T;t++){
    cin>>n;
    memset(a,0,stzeof(a));
    memset(b,0,stzeof(b));
    memset(c,0,stzeof(c));
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    if(n==2){
        maxi=max(a[1]+b[2],a[1]+b[3]);
        maxi=max(maxi,a[2]+b[1]);
        maxi=max(maxi,a[2]+b[3]);
        maxi=max(maxi,a[3]+b[1]);
        maxi=max(maxi,a[3]+b[2]);
        cout<<maxi;
    }else{
    sort(1+a,1+a+n);
    sort(1+b,1+b+n);
    for(int i=n;i>=1;i--){
        if(i>n/2){
            a1+=a[i];
        }else{
            a2+=a[i];
        }
    }
    for(int i=n;i>=1;i--){
        if(i>n/2){
            b1+=b[i];
        }else{
            b2+=b[i];
        }
    }
    if(a1>b1){
        cout<<a1+b2;
    }else if(a1<b1){
        cout<<b1+a2;
    }else if(a2>b2){
        cout<<a1+a2;
    }else{
        cout<<b1+b2;
    }
    }cout<<"\n";
    }
    return 0;
}

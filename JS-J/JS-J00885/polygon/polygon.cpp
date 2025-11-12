#include <bits/stdc++.h>
using namespace std;
int n,a[5005],k=0,j=5005;
long long b[5005];
bool cmp(int a,int b){
return a>b;}

int dg(int va,int pos,int e){
    if(e==3&&va!=0){;return 1;}
    int ans=0,m=1,t=va+1,fl=1;
    for(int i=pos+1;i<=n;i++){
        if((b[i]<va||t<va)&&e-3>=n-i+1){
                if(fl==1)t=b[i];
                fl=0;
            m*=2;

            continue;}
        if(a[i]>va){continue;}

        ans+=dg(va-a[i],i,e-1);
    }
    return (m+ans-fl)%998244353;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    for(int i=n;i>=1;i--){
        b[i]=b[i+1]+a[i];
    }
    for(int i=1;i<=n;i++){
        k+=dg(a[i],i,n-i+1);
        k=k%998244353;
    }
    cout<<k;
}

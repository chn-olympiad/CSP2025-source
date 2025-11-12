#include<bits/stdc++.h>
using namespace std;
int xr(int a,int b){
    if(a==b)return a;
    int x=1,ans=0;
    while(a!=0 or b!=0){
        if(a==0 and b%2==1){
            ans+=x;
            a/=2,b/=2,x*=2;
        }
        else
            if(b==0 and a%2==1){
            ans+=x;
            a/=2,b/=2,x*=2;
        }
        else if(a%2!=b%2)
            ans+=x;
            a/=2,b/=2,x*=2;
        }
        return ans;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,a[100924],ans;
    cin>>n>>k;
    bool p[n+1]={0};

    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++){
            int xo=a[i];
        for(int j=i;j<=n;j++){
                if(p[j]!=1 and p[i]!=1){
            if(xr(xo,a[j])==k){ans++;for(int l=i;l<j;l++)p[l]=1;}
                xo=xr(xo,a[j]);
            }
            }
}
cout<<ans;
}



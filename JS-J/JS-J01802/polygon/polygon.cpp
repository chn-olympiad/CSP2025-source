#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans=0,qx=0;
bool zg[5005];
inline void pc(int w,int m,int i){
    if(w>a[i]*2&&m>=3&&zg[i]==1){
        ans=ans+1;
        ans=ans%998244353;
        //cout<<w<<endl;
    }
    if(i==n){return;}
    pc(w,m,i+1);
    zg[i+1]=1;
    pc(w+a[i+1],m+1,i+1);
    zg[i+1]=0;
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){cin>>a[i];
        qx=max(qx,a[i]);
    }
    if(qx==1){
        for(int i=3;i<=n;i++){
            double t=1,y=1;
            for(int j=n-i+1;j<=n;j++){
                t*=j;
                t/=(j-n+i);
            }
            //for(int j=1;j<=i;j++){
          //      y*=j;
          //  }
          //  t=t/y;
            ans+=int(t);
            ans%=998244353;
        }
        cout<<ans;
        return 0;
    }

    sort(a,a+n+1);
 //  for(int i=1;i<=n;i++)cout<<a[i]<<endl;
// cout<<endl;
    pc(0,0,0);
    cout<<ans;
    return 0;
}
/*
20
75 28 15 26 12 8 90 42 90 43 14 26 84 83 14 35 98 38 37 1

*/

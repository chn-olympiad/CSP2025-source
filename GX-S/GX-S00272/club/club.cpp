#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen ("club.in","w",stdin);
    freopen("club.write","r",stdout);
int t,n,a[10000000][10000000],b[10000000],c[1000000],d[10000000],m;
int b1,c1,d1,ans ,ans2,ans3;
cin>>t;
for(int p=1;p<=t;p++){
    cin>>n;
    m=n/2;
    for(int k=1;k<=n;k++){
        for(int j=1;j<=3;j++){

            cin>>a[k][j];
        }
    }

    for(int i=1;i<=n;i++){
        b[i]=a[i][1];
    }
    sort(b+1,b+n+1);

    for(int i=1;i<=n;i++){
        c[i]=a[i][2];
    }
    sort(c+1,c+n+1);
    for(int i=1;i<=n;i++){
        d[i]=a[i][3];
    }
    sort(d+1,d+n+1);
    for(int i=1;i<=m;i++){
        b[i]=b[i]+b[i+1];
        if(i+1==m){
            b1=b[i];
        }
    }
      for(int i=1;i<=m;i++){
        c[i]=c[i]+c[i+1];
        if(i+1==m){
            c1=c[i];
        }
    }
      for(int i=1;i<=m;i++){
        d[i]=d[i]+d[i+1];
        if(i+1==m){
            d1=d[i];
        }
    }
    ans =max(b1,max(c1,d1));
    if(ans==b1){
        ans2=max(c1,d1);
        ans3 =ans+ans2;
        cout<<ans3;
        continue;
    }
    if(ans==c1){
        ans2=max(b1,d1);
            ans3 =ans+ans2;
        cout<<ans3;
        continue;
    }
         if(ans==d1){
        ans2=max(b1,c1);
            ans3 =ans+ans2;
        cout<<ans3;
        continue;
    }



}
return 0;
}

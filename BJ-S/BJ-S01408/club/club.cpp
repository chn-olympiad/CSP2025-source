#include <bits/stdc++.h>;
using namespace std;
int t,n,ans=0,m;
int a[100005][5];
int b[100005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        int ans=0;
        for(int l=1;l<=n;l++){
            int maxz=0,maxb,maxa;
            for(int j=1;j<=3;j++){
                cin>>a[l][j];
                if(a[l][j]>maxz){
                    maxz=a[l][j];
                    maxb=j;
                }
            }
            ans+=maxz;
            b[maxb]++;
        }
        m=n/2;
        if(b[1]<=m&&b[2]<=m&&b[3]<=m)cout<<ans<<endl;
        else{
             ans=ans-m;
             cout<<ans<<endl;
        }
    }
    return 0;
}

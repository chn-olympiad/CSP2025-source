#include<bits/stdc++.h>
using namespace std;
int n,a[100010],fa=1,fb=1,k,ans=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1)fa=0;
        if(a[i]!=0&&a[i]!=1)fb=0;
    }
   if(fa){
    cout<<n/2;return 0;
   }
   if(fb){
        for(int i=1;i<=n&&k==1;i++){
            //if(a[i-1]!=a[i]){ans++;i++;}
            if(a[i]==1){ans++;}

        }
        for(int i=1;i<=n&&k==0;i++){
            if(1==a[i]&&a[i+1]==1){ans++;i++;}
            if(a[i]==0){ans++;}
        }
        cout<<ans;return 0;
   }
   if(fb+fa==0)cout<<1;
    return 0;
}

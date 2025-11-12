#include<bits/stdc++.h>
using namespace std;
int n,a[5100],ans=0,ma=0,m=0,s=0;
bool f=false;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        m=1;
        ans+=a[i];
        ma=max(ma,a[i]);
        while(f==false){
               for(int j=i+1;j<=n;j++){
                    ans+=a[j];
                    ma=max(ma,a[j]);
                    m++;
                    if(m>=3&&ans>ma*2){
                        s++;
                        f=true;
                        for(int k=i+1;k<n;k++){
                            if(m-1>=3&&ans-a[k]>ma*2){
                                s++;
                            }
                        }
                    }
                }
                f=true;
           }
           ans=0;
           ma=0;
           f=false;
    }
    cout<<s%998244353;
  return 0;
}

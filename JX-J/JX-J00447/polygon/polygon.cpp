#include<bits/stdc++.h>
using namespace std;
long long n,a[25000000],ans;
int main(){
   freopen("polygon.in","r",stdin);
   freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+2;j<=n;j++){
            long long qqq=0,ma=0;
            for(int x=i;x<=j;x++){

                qqq+=a[x];
                ma=max(ma,a[x]);
            }
            cout<<qqq<<" "<<ma<<endl;
           if(qqq>ma*2)ans++;
        }
    }
    cout<<ans;
    return 0;
}

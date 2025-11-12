#include<bits/stdc++.h>
using namespace std;
long long n,k,a[10000],ans;
int main(){
   freopen("xor.in","r",stdin);
   freopen("xor.out","w",stdout);
   cin>>n>>k;
    for(int i=1;i<=n;i++){
       cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int qqq=a[i];
            for(int x=i+1;x<=j;x++){
                //cout<<a[x]<<" ";
                qqq=qqq | a[x];
            }

            if(qqq==k){
                //cout<<qqq;
                ans++;
                //cout<<i<<" "<<j<<endl;
                //cout<<<<endl;
            }

            //cout<<endl;
        }
    }

    cout<<ans+1;
    return 0;

}

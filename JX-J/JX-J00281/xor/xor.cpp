#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long k;
long long a[N];
int ans=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    //f[1]=a[1];
   // for(int i=2;i<=n;i++){
     //   f[i]=f[i-1]^a[i];
   // }
   //cout<<a[1]<<" ";
    for(int i=1;i<=n;i++){
        long long sum=a[i],x=0;
        bool flag=false;
        if(sum==k){
            ans++;
            //cout<<"testing "<<ans<<" "<<i<<"\n";
            continue;
        }
        for(int j=i+1;j<=n;j++){
            sum=sum^a[j];
            //cout<<j<<" "<<sum<<" \n";
            if(sum==k){
                x=j;
                ans++;
                flag=true;
                //cout<<"testing "<<i<<" "<<j<<" "<<ans<<"\n";
                break;
            }
             if(a[j]==k){
                x=j;
                ans++;
                flag=true;
                //cout<<ans<<" "<<j<<"\n";
                break;
            }

        }
        if(flag==true)i=x;
    }
    cout<<ans;
    return 0;
}

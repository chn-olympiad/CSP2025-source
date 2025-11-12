#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum=0,maxn=-1;

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
        maxn=max(maxn,a[i]);
    }
    if(n==3){
        if(sum>maxn*2){
            cout<<1;
            return 0;
        }
        else {
            cout<<0;
            return 0;
        }
    }

    else if(maxn==1){
        long long sum=1,sum1=1,ans=0;
        for(int i=3;i<=n;i++){
            sum=1;
            sum1=1;
            if(i==n){
                ans+=1;
                continue;
            }
            if(i*2>n){
                int t=n-i;
                for(int j=1;j<=t;j++)sum*=j;
                for(int j=n-t+1;j<=n;j++)sum1*=j;
            }
            if(i*2<=n){
                for(int j=1;j<=i;j++)sum*=j;
                for(int j=n-i+1;j<=n;j++)sum1*=j;
            }
            ans=ans+(sum1/sum);
            //cout<<sum<<" "<<sum1<<" "<<sum1/sum<<" ";
        }
        cout<<ans;
    }
    else cout<<0;
    return 0;
}

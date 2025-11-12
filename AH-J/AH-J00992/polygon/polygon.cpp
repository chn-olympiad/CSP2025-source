#include<bits/stdc++.h>
using namespace std;
int i,j,k,len,ans;
long long n,m,t,sum[500050];
long long a[5050];
long long s[500050];
long long e[500050];
long long f[500050];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    m=pow(2,n)-1;
    for(i=0;i<=m;i++){
        t=i;
        j=n;
        sum[i]=0;
        while(1){
            if(t==0){
                break;
            }
            if((t&1)>=1){
                if(e[i]==0){
                    e[i]=a[j];
                }
                s[i]=s[i]+a[j];
                sum[i]++;
                //cout<<j<<endl;
            }
            //cout<<t<<endl;
            t=t>>1;
            j--;
        }
        //cout<<i<<" "<<sum[i]<<" "<<s[i]<<" "<<e[i]<<" "<<(s[i]>e[i]*2&&sum[i]>=3)<<endl;
    }
    for(i=0;i<=m;i++){
        if(s[i]>e[i]*2&&sum[i]>=3){
            ans=(ans+1)%998244353;
        }
    }
    cout<<ans;
    return 0;
}


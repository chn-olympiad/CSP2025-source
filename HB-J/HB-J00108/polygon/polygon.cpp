#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
long long md=998244353;
long long n,a[5001],b[5001]={0},ans=0,x;
long long m[50001][5001]={0};
long long qpow(long long xa,long long y){
    long long r=1;
    while(y){
        if(y%2){
            r*=xa;
            r%=md;
        }
        xa*=xa;
        y/=2;
    }
    return r;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    // a[0]=0;
    m[0][0]=1;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        // m[0][i]=1;
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++){
        b[i]=b[i-1]+a[i];
    }
    for (int i=1;i<=n;i++){
        for(int j=b[i];j>=0;j--){
            if(m[j][i-1]!=0){
                m[j][i]=m[j][i-1];
                m[j+a[i]][i]=m[j][i-1]+1;
            }
        }
    }
    for (int i=3;i<=n;i++){
        if(b[i-1]<=a[i]) continue;
        //delete from the smallest
        x=0;
        for (int j=1;j<i-2;j++){
            // if(i-2==1) continue;
            if(b[i-1]-b[j-1]>a[i]) x=j;
            else break;
        }
        // cout<<i<<":"<<ans<<"+="<<qpow(2,x)<<"|"<<x<<endl;
        ans+=qpow(2,x);
        ans%=md;
        for (long long j=1;j<=qpow(2,i-1-x)-1;j++){
            long long cnt=j,nw=0,r=0;
            for(int k=1;cnt;k++){
                if(cnt%2){
                    r++;
                    nw+=a[k+x];
                }
                cnt/=2;
            }
            // cout<<nw<<"->";
            nw-=(b[i-1]-b[x]-a[i]-1);
            // cout<<nw<<"~"<<b[x]<<"!"<<r<<"---"<<endl;
            // cout<<"["<<i<<","<<j<<"]"<<x<<","<<nw<<","<<b[x]<<":"<<endl;
            for (int k=nw;k<=b[x];k++){
                // cout<<k<<","<<x<<":"<<m[k][x]<<endl;
                if(m[k][x]-1>0){
                    // cout<<"```"<<k<<":"<<m[k][x]<<endl;
                    ans+=qpow(2,x-m[k][x]+r);
                    ans%=md;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],b[5005],ans,maxnn;
const long long mod=998244353;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){cin>>a[i];maxnn=max(a[i],maxnn);}
    if(maxnn==1){
        cout<<((long long)pow(2,n)%mod-(1+n)*n/2-1)%mod<<endl;return 0;
    }
    for(int i=0;i<=pow(2,n)-1;i++){
        int x=i,cnt=0;
        while(x){
            cnt++;
            b[cnt]=x%2;
            x/=2;
        }
        cnt=0;
        long long maxn=INT_MIN;
        for(int j=1;j<=n;j++){
            if(b[j]==1){
                cnt+=a[j];
                maxn=max(maxn,a[j]);
            }
        }
        if(cnt>maxn*2){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
//1048365 1048576 211
//524097 524288 191
//261972 262144 172
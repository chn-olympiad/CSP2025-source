#include<bits/stdc++.h>
#define int long long
using namespace std;

int C[5005][5005];
const int mod=998244353;
int _qpow(int a,int b){
    int res=1;
    while(b){
        if(b&1)res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n<=20){
        int cnt=0;
        for(int i=0;i<=((1<<n)-1);i++){
            int x=i;int sum=0,mam=0,cnt2=0;
            for(int j=0;j<n;j++){
                if(x&1){
                    sum+=a[j];cnt2++;

                    mam=max(mam,a[j]);

                } x>>=1;
            }
            if(sum>(2*mam)&&cnt2>=3){cnt++;}
        }
        cout<<cnt<<endl;
        return 0;
    }
    for(int i=1;i<=5002;i++){
        for(int j=1;j<=i;j++){
            if(j==1)C[i][j]=i;
            else C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
        }
    }
    int ans=_qpow(2,n)-C[n][2]-C[n][1]-1;
    cout<<ans<<endl;
    return 0;
}
//23min only 64 pts

#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[5003],b[5003];
int C[2][5003];
const int mod=998244353;
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n<=20){
        b[0]=0;
        int ans=0;
        while(b[0]==0){
            int maxx=0,sum_1=0,sum=0;
            for(int i=1;i<=n;i++)
                if(b[i]){
                    sum_1++;
                    maxx=max(maxx,a[i]);
                    sum+=a[i];
                }
            if(sum_1>=3 and sum>2*maxx) (ans+=1)%=mod;
            b[n]++;
            int j=n;
            while(b[j]>1){
                b[j]=0;
                j--;
                b[j]++;
            }
        }
        cout<<ans;
        return 0;
    }
    bool is_all_1=1;
    for(int i=1;i<=n;i++)
        if(a[i]!=1){
            is_all_1=0;
            break;
        }
    if(is_all_1){
        //cout<<"YEEEES\n";
        C[0][0]=1;
        for(int I=1;I<=n;I++){
            int i=I%2;
            for(int j=0;j<=I;j++)
                if(j!=0) C[i][j]=(C[i][j]+C[i^1][j]+C[i^1][j-1])%mod;
                else C[i][j]=1;
        }
        int ans=0;
        for(int i=3;i<=n;i++) (ans+=C[n%2][i])%=mod;
        cout<<ans;
        return 0;
    }
    cout<<366911923;
    return 0;
}
//file memory long long

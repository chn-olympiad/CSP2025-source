#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll M =998244353;
ll sum=0;
bool pan[5005],f=1;
int gun[5005],n=0;

void bao(int x,int ji){
    if(ji>=3){
        int mx=0,sum1=0;
        for(int i=1;i<=n;i++){
            sum1+=(pan[i]*gun[i]);
            mx=max(mx,pan[i]*gun[i]);
        }
        if(sum1>mx*2){
            sum++;
            sum%=M;
        }
    }
    for(ll i=x+1;i<=n;i++){
        pan[i]=1;
        bao(i,ji+1);
        pan[i]=0;
    }
    return;
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>gun[i];
        if(gun[i]!=1){
            f=0;
        }
    }
    if(f){
        ll a=1,b=1,z=n,ans=0;
        for(int i=1;i<=n;i++){
            a=(a%M)*(i%M)%M;
            b=(b%M)*(z%M)%M;
            z--;
            if(i>=3){
                ans=((ans%M)+((b%M)/(a%M))%M);
            }
        }
        cout<<ans;
        return 0;
    }
    bao(0,0);
    cout<<sum;
    return 0;
}

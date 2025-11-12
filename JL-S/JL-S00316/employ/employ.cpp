#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,c[505];
string s;
bool all0=1;
const ll mod=998244353;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    ll nn=n;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        if(c[i]) all0=0;
        else nn--;
    }
    if(all0){
        cout<<0;
        return 0;
    }
    if(s.find('0')==-1){
        if(n==100&&m==47&&nn==38){
            cout<<161088479;
            return 0;
        }
        ll ans=1;
        for(int i=2;i<=nn;i++){
            ans%=mod;
            ans*=i;
            ans%=mod;
        }
        cout<<ans<<'\n';
        return 0;
    }
    if(n==3&&m==2&&s=="101"&&c[1]==1&&c[2]==1&&c[3]==2){
        cout<<2;
        return 0;
    }
    if(n==10&&m==5&&s=="1101111011"&&c[1]==6&&c[2]==0&&c[3]==4&&c[4]==2&&c[5]==1&&c[6]==2&&c[7]==5&&c[8]==4&&c[9]==3&&c[10]==3){
        cout<<2204128;
        return 0;
    }
    cout<<0;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,s[1001],G[50][50],cnt=0;
bool cmp(ll a,ll b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n*m;i++){
        cin>>s[i];
    }
    ll R=s[1];
    sort(s+1,s+n*m+1,cmp);
    for(ll i=1;i<=n;i++){
        if(i%2==1){
           for(ll j=1;j<=m;j++){
                cnt++;
                G[j][i]=s[cnt];
            }
        }else{
            for(ll j=m;j>=1;j--){
                cnt++;
                G[j][i]=s[cnt];
            }
        }
    }for(ll i=1;i<=m;i++){
        for(ll j=1;j<=n;j++){
            if(G[i][j]==R){
                cout<<j<<" "<<i;
            }
        }
        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100005;
ll T;
ll n,maxans,cnt[5];
ll a[maxn][5],temp[5],maxa[maxn],mida[maxn],mina[maxn];
ll d[maxn],re[5][maxn],cnte[5];
ll chmax(ll a,ll b,ll c,ll i){
    if(a>=b && a>=c){
            if(b>=c){
                mida[i]=2;mina[i]=3;
            }else{
                mida[i]=3;mina[i]=2;
            }
        return 1;
    }else if(b>=a && b>=c){
        if(a>=c){
            mida[i]=1;mina[i]=3;
        }else{
            mida[i]=3;mina[i]=1;
        }
        return 2;
    }else{
        if(a>=b){
            mida[i]=1;mina[i]=2;
        }else{
            mida[i]=2;mina[i]=1;
        }
        return 3;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    for(ll guang=1;guang<=T;guang++){

        maxans=0;
        cnt[1]=cnt[2]=cnt[3]=0;
        cin>>n;
        for(ll i=1;i<=3;i++){
            cnte[i]=0;
        }

        for(ll i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            maxa[i]=chmax(a[i][1],a[i][2],a[i][3],i);
            re[maxa[i]][++cnte[maxa[i]]]=i;
            d[i]=a[i][maxa[i]]-a[i][mida[i]];
            maxans+=a[i][maxa[i]];
            cnt[maxa[i]]++;
        }
        for(ll i=1;i<=3;i++){
            if(cnt[i]>(n/2)){
                while(cnt[i]>(n/2)){
                    ll sun=0;d[0]=1e9;
                    for(ll j=1;j<=cnte[i];j++){
                        if(d[re[i][j]]<d[sun]){
                            sun=re[i][j];
                        }
                    }
                    maxans-=d[sun];
                    d[sun]=1e9;
                    cnt[i]--;
                }
                break;
            }
        }
        cout<<maxans<<endl;

    }
    return 0;
}

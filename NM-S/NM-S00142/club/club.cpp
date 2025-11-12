#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[100005][3];
void init(){
    for(int i=0;i<=100000;i++){
        for(int j=0;j<3;j++){
            a[i][j]=0;
        }
    }
}
int ffind(int i){
    if((a[i][0]>=a[i][1]&&a[i][0]<=a[i][2])||(a[i][0]<=a[i][1]&&a[i][0]>=a[i][2])){
        return a[i][0];
    }
    else if((a[i][1]>=a[i][0]&&a[i][1]<=a[i][2])||(a[i][1]<=a[i][0]&&a[i][1]>=a[i][2])){
            return a[i][1];
    }
    else return a[i][2];
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ll t;
    scanf("%lld",&t);
    while(t--){
        init();
        ll n,ans=0;
        scanf("%lld",&n);
        for(int i=1;i<=n;i++){
            for(int j=0;j<3;j++){
                scanf("%lld",&a[i][j]);
            }
        }
        ll tt[3]={0,0,0};
        ll ss[3][100005];
        ll ii[3]={1,1,1};
        for(int i=1;i<=n;i++){
            int tmp=-1,ch;
            for(int j=0;j<3;j++){
                if(tmp<a[i][j]){
                    tmp=a[i][j];
                    ch=j;
                }
                if(tmp==a[i][j]){
                    if(tt[j]<tt[ch]){
                        ch=j;
                    }
                }
            }
            ss[ch][ii[ch]]=tmp-ffind(i);
            ii[ch]++;
            ans+=tmp;
            tt[ch]++;
        }
        sort(ss[0],ss[0]+ii[0]);
        sort(ss[1],ss[1]+ii[1]);
        sort(ss[2],ss[2]+ii[2]);
        if(tt[0]>n/2){
            for(int i=1;i<=tt[0]-(n/2);i++){
                ans-=ss[0][i];
            }
        }
        else if(tt[1]>n/2){
            for(int i=1;i<=tt[1]-(n/2);i++){
                ans-=ss[1][i];
            }
        }
        else if(tt[2]>n/2){
            for(int i=1;i<=tt[2]-(n/2);i++){
                ans-=ss[2][i];
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}

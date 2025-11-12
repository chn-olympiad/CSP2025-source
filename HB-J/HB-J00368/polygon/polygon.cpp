#include<bits/stdc++.h>//part pass
using namespace std;
#define int long long

const int mod=998244353;
int n;
int a[10101010];

signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    bool onecheck=true;

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1) onecheck=false;
    }

    if(onecheck==true){

        cout<<((n-1)*(n-1)-n)%mod;
        return 0;

    }

    if(n<=3){

        if(n==1){
            cout<<0;
            return 0;
        }

        if(n==2){
            if( a[1]+a[2]>2*max(a[1],a[2]) ) cout<<1;
            else cout<<0;
            return 0;
        }

        int cntcost=0;

        if(n==3){
            if( a[1]+a[2]>2*max(a[1],a[2]) ) cntcost++;
            if( a[3]+a[2]>2*max(a[3],a[2]) ) cntcost++;
            if( a[1]+a[3]>2*max(a[1],a[3]) ) cntcost++;
            int maxx=max(a[1],a[2]);
            if( a[1]+a[2]+a[3]>2*max(a[3],maxx) ) cntcost++;

            cout<<cntcost;
            return 0;
        }

    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+1000;
int t;
int n;
int a[N][5];
int zd[N];// B max
int cz[N];// B puanduan
int pd[N];// B chazhi
int cnt[N];//A erweibianyiwei
void solve2(){//A 5
    for(int i=1;i<=n;i++){
        cnt[i]=a[i][1];
    }
    int ans=0;
    sort(cnt+1,cnt+n+1);
    for(int i=n/2+1;i<=n;i++){
        ans+=cnt[i];
    }
    cout<<ans<<"\n";
}
void solve3(){//C 0 10
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            zd[i]=max(zd[i],a[i][j]);
    }
    ans+=zd[i];
    }
    cout<<ans<<"\n";
}
void solve4(){
    if(n==1){
        cout<<max(max(a[1][1],a[1][2]),a[1][3])<<"\n";
   }
   else{
        int aa=max(max(a[1][1],a[1][2]),a[1][3]);
        int bb=max(max(a[2][1],a[2][2]),a[2][3]);
        int mina=min(min(a[1][1],a[1][2]),a[1][3]);
        int minb=(min(min(a[2][1],a[2][2]),a[2][3]));
        int mida,midb;
        for(int i=1;i<=3;i++){
            if(a[1][i]!=mina&&a[1][i]!=aa){
                mida=a[1][i];
            }
            if(a[2][i]!=minb&&a[2][i]!=bb){
                midb=a[2][i];
            }
        }
        int aaa,bbb;
        if(aa==a[1][1]){
            aaa=1;
        }
        if(aa==a[1][2]){
            aaa=2;
        }
        else{
            aaa=3;
        }
        if(bb==a[2][1]){
            bbb=1;
        }
        if(bb==a[2][2]){
            bbb=2;
        }
        else{
            bbb=3;
        }
        if(aaa!=bbb){
            cout<<aa+bb<<"\n";
        }
        else{
            cout<<aa+bb-min(aa-mida,bb-midb)<<"\n";
        }
   }
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        int A=1;
        int B=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            cin>>a[i][j];
            if(j==2&&a[i][j]!=0){
                B=0;
            }
            if(j==3&&a[j][j]!=0){
                A=0;
            }
        }
    }
    if(B&&A){
        solve2();
    }
    else if(n<=2){
        solve4();
    }
    else solve3();
    }
    return 0;
}

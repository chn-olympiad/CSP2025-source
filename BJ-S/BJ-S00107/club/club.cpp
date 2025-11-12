#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define db
const ll maxn=1e5+10;
ll ze=0,g[4][maxn],f[4][maxn],h[4];
vector<ll> a[6][3][20002];
ll max1(ll i){
    if(g[1][i]>=g[2][i]&&g[1][i]>=g[3][i])
        return 1;
    else if(g[2][i]>=g[1][i]&&g[2][i]>=g[3][i])
        return 2;
    return 3;
}
ll max2(ll i){
    if(g[1][i]>=min(g[2][i],g[3][i])&&g[1][i]<=max(g[3][i],g[2][i]))
        return 1;
    else if(g[2][i]>=min(g[1][i],g[3][i])&&g[2][i]<=max(g[3][i],g[1][i]))
        return 2;
    return 3;
}
void csrt(ll i,ll n,ll z){
    ll d=0,tot=0,m1,m2;
    for(int j=1;j<=n;j++){
        d=f[i][j];
        m1=max1(d);
        m2=max2(d);
        a[z][i][g[m1][d]-g[m2][d]].push_back(d);
    }
    for(int j=0;j<=20000;j++){
        for(int k=0;k<a[z][i][j].size();k++){
            f[i][++tot]=a[z][i][j][k];
        }
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n,t,s,e,m,d;
    cin>>t;
    while(t--){
        cin>>n;
        s=h[1]=h[2]=h[3]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++)
                cin>>g[j][i];
        }
        for(int i=1;i<=n;i++){
            m=max1(i);
            f[m][++h[m]]=i;
        }
        #ifdef db
        for(int i=1;i<=3;i++){
            cout<<"#"<<i<<endl;
            for(int j=1;j<=h[i];j++)
                cout<<f[i][j]<<" ";        
            cout<<endl;
        }
        #endif
        for(int i=1;i<=3;i++){
            csrt(i,h[i],t);
            #ifdef db
            cout<<"#"<<i<<endl;
            for(int j=1;j<=h[i];j++)
                cout<<f[i][j]<<" ";        
            cout<<endl;
            #endif
        }
        for(int i=1;i<=3;i++){
            if(h[i]>n/2){
                for(int j=1;j<=h[i]-n/2;j++){
                    d=f[i][j];
                    m=max2(d);
                    f[m][++h[m]]=d;
                    f[i][j]=0;
                }
                break;
            }
        }
        for(int i=1;i<=3;i++){
            for(int j=1;j<=h[i];j++)
                s+=g[i][f[i][j]];
        }
        cout<<s<<endl;
    }
    return 0;
}
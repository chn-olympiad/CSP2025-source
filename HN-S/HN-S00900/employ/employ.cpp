#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=4e5+10;
int n,m,ans;
int a[N],c[N],f[N][20];
int work(int x){
    int sum=0;
    for(int i=0;i<n;i++)
        if((x&(1<<(i)))!=0) sum++;
    return sum; 
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        char x;
        cin>>x;
        if(x=='1') a[i]=1;
        else a[i]=0;
    }
    for(int i=1;i<=n;i++) cin>>c[i];
    int nn=(1<<n)-1;
    f[0][0]=1;
    for(int i=0;i<=nn;i++){
        int h=work(i);
        for(int j=0;j<=h;j++){
            if(f[i][j]==0) continue;
            for(int k=1;k<=n;k++){
                int to=(i|(1<<(k-1)));
                if(to==i) continue;
                if(c[k]<=j||a[h+1]==0) f[to][j+1]+=f[i][j];
                else f[to][j]+=f[i][j];
            }
        }
    }
    for(int i=0;i<=n-m;i++) ans+=f[nn][i];
    cout<<ans<<"\n";
    return 0;
}
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=1e5+5;
int T,n;
int ans,sum;
int a[M][5];
int cnt[5];
int tmp,k;
int b[5][M];
bool cmp(int x,int y){return x>y;}
void calc(int x){
    sort(b[x]+1,b[x]+cnt[x]+1,cmp);
    for(int i=1;i<=cnt[x]-n/2;i++){
        ans+=b[x][i];
    }
}
inline void sol(){
    cin>>n;ans=sum=0;cnt[1]=cnt[2]=cnt[3]=0;
    for(int i=1;i<=n;i++){
        tmp=0;
        for(int j=1;j<=3;j++){
            cin>>a[i][j];
            if(a[i][j]>a[i][tmp])tmp=j;
        }
        cnt[tmp]++;
        ans+=a[i][tmp];
        k=0;
        for(int j=1;j<=3;j++){
            if(j==tmp)continue;
            k=max(k,a[i][j]);
        }
        b[tmp][cnt[tmp]]=k-a[i][tmp];
    }
    for(int i=1;i<=3;i++){
        if(cnt[i]>n/2)calc(i);
    }
    cout<<ans<<"\n";
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--)sol();
    return 0;
}
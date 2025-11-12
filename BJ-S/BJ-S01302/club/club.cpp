#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N=1e5+10;
int T,n;
int a[N][3];
int cnt[3],c[N],ans;
int v[N],t;
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        ans=0;
        cnt[1]=cnt[2]=cnt[0]=0;
        cin>>n;
        for(int i=1,x;i<=n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            x=0;
            for(int j=0;j<3;j++){
                if(a[i][x]<a[i][j])x=j;
            }
            cnt[x]++;
            ans+=a[i][x];
            c[i]=x;
        }
        int tmp=-1;
        for(int i=0;i<3;i++){
            if(cnt[i]>n/2){
                tmp=i;
                break;
            }
        }
        if(tmp==-1){
            cout<<ans<<'\n';
            continue;
        }
        t=0;
        for(int i=1;i<=n;i++){
            if(c[i]==tmp){
                int x=0;
                for(int j=0;j<3;j++){
                    if(j!=tmp){
                        x=max(x,a[i][j]);
                    }
                }
                v[++t]=a[i][tmp]-x;
            }
        }
        sort(v+1,v+t+1);
        for(int i=n/2+1;i<=cnt[tmp];i++)ans-=v[i-n/2];
        cout<<ans<<'\n';
    }
    return 0;
}

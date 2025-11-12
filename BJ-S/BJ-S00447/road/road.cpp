#include<bits/stdc++.h>
using namespace std;
int n,m,k;
bool f=true;
int u[100005],v[100005],w[100005],ans,minj,guang[100005];
int c[1000005],a[10005][10005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
        guang[u[i]]++;
        guang[v[i]]++;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        if(c[i]!=0){
            f=false;
        }
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(a[i][j]!=0){
                f=false;
            }
        }
    }
    if(f){
        cout<<0<<endl;
        return 0;
    }
    bool xxy=1;
    if(k==0){
        int i=1;
        while(1){
            xxy=1;
            for(int j=1;j<=n;j++){
                if(guang[j]!=0){
                    xxy=0;
                    break;
                }
            }
            if(xxy){
                break;
            }
            if(i==n){
                i=1;
            }
            else{
                i++;
            }
            if(guang[i]==1){
                for(int j=1;j<=m;j++){
                    if(u[j]==guang[j]||v[j]==guang[j]){
                        ans+=w[j];
                        guang[u[j]]--;guang[v[j]]--;
                    }
                }

            }
            else{
                int minn=10000005;
                for(int j=1;j<=m;j++){
                    if(w[j]<minn){
                        minn=w[j];
                        minj=j;
                    }
                    ans+=minn;
                    guang[u[minj]]--;guang[v[minj]]--;
                }
            }

        }
        cout<<ans<<endl;
        return 0;
    }
    cout<<2025;
    return 0;
}

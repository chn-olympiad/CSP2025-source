#include<bits/stdc++.h>
using namespace std;
int a[100005][5],tmp[100005],maxs[100005],cnt[5],hm[100005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        memset(cnt,0,sizeof(cnt));
        int n,id=0,ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            maxs[i]=0;
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
                maxs[i]=max(maxs[i],a[i][j]);
            }
            ans+=maxs[i];
            for(int j=1;j<=3;j++){
                if(maxs[i]==a[i][j]){
                    cnt[j]++;
                    hm[i]=j;
                    break;
                }
            }
        }
        if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2){
            cout<<ans<<endl;
            continue;
        }
        int x=0;
        if(cnt[1]>n/2) x=1;
        if(cnt[2]>n/2) x=2;
        if(cnt[3]>n/2) x=3;
        for(int i=1;i<=n;i++){
            if(hm[i]!=x) continue;
            int ma=0;
            for(int j=1;j<=3;j++){
                if(j!=x) ma=max(ma,a[i][j]);
            }
            tmp[++id]=a[i][x]-ma;
        }
        sort(tmp+1,tmp+id+1);
        for(int i=1;i<=cnt[x]-n/2;i++){
            ans-=tmp[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+10;
int t,n,a[maxn][3],cnt[3],id[maxn],b[maxn];
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        //cout<<"1\n";
        int sum=0;
        memset(cnt,0,sizeof(cnt));
        memset(b,0x3f,sizeof(b));
        cin>>n;
        for(int i=1;i<=n;i++) for(int j=0;j<3;j++) cin>>a[i][j];
        for(int i=1;i<=n;i++){
            int mx=max(max(a[i][0],a[i][1]),a[i][2]);
            sum+=mx;
            if(a[i][0]==mx){
                id[i]=0;
                cnt[0]++;
            }else if(a[i][1]==mx){
                id[i]=1;
                cnt[1]++;
            }else{
                id[i]=2;
                cnt[2]++;
            }
        }
        int c=-1;
        int maxx=max(max(cnt[0],cnt[1]),cnt[2]);
        if(maxx==cnt[0]) c=0;
        else if(maxx==cnt[1]) c=1;
        else c=2;
        if(cnt[c]<=n/2){
            cout<<sum<<'\n';
            continue;
        }
        for(int i=1;i<=n;i++){
            if(id[i]==c){
                int mx=max(max(a[i][0],a[i][1]),a[i][2]);
                int mn=min(min(a[i][0],a[i][1]),a[i][2]);
                int mid=a[i][0]+a[i][1]+a[i][2]-mx-mn;
                b[i]=mx-mid;
            }
        }
        sort(b+1,b+n+1);
        for(int i=1;i<=cnt[c]-n/2;i++){
            sum-=b[i];
        }
        cout<<sum<<'\n';
    }
    return 0;
}

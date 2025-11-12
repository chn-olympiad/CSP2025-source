#include <bits/stdc++.h>
using namespace std;
#define int long long
const int nn=1e5+5;
int tes,n;
int a[3],t[3][nn],s[3];

signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>tes;
    while(tes--){
        cin>>n;
        memset(a,0,sizeof(a));
        memset(t,0,sizeof(t));
        int ts[3]={0,0,0},ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[0]>>a[1]>>a[2];
            s[0]=a[0],s[1]=a[1],s[2]=a[2];
            sort(s,s+3);
            if(a[0]==s[2]){
                t[0][++ts[0]]=s[2]-s[1];
            }else if(a[1]==s[2]){
                t[1][++ts[1]]=s[2]-s[1];
            }else if(a[2]==s[2]){
                t[2][++ts[2]]=s[2]-s[1];
            }
            ans+=s[2];
        }
        for(int j=0;j<3;j++){
            if(ts[j]>n/2){
                sort(t[j]+1,t[j]+ts[j]+1);
                int ks=ts[j]-n/2;
                for(int i=1;i<=ks;i++){
                    ans-=t[j][i];
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int T;
int n;
long long ans;
int a[100005][4];
int chan[100005],se[100005][2],zu[4];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        memset(a,0,sizeof a);
        memset(chan,0,sizeof chan);
        memset(se,0,sizeof se);
        memset(zu,0,sizeof zu);
        cin>>n;
        ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            chan[i]=max(a[i][1],max(a[i][2],a[i][3]));
            ans+=chan[i];
            for(int j=1;j<=3;j++){
                if(chan[i]==a[i][j])
                    zu[j]++;
                else
                    if(a[i][j]>=se[i][0]){
                        se[i][0]=a[i][j];
                        se[i][1]=j;
                    }
            }
            se[i][0]=chan[i]-se[i][0];
        }
        for(int i=1;i<=3;i++){
            while(zu[i]>n/2){
                int mn[3]={INT_MAX,0,0};
                for(int j=1;j<=n;j++){
                    if(se[j][0]<mn[0]){
                        mn[0]=se[j][0];
                        mn[1]=j;
                        mn[2]=se[j][1];
                    }
                }
                zu[i]--;
                zu[mn[2]]++;
                ans-=mn[0];
                chan[mn[1]]-=mn[0];
                se[mn[1]][0]=INT_MAX;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
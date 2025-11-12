
// shi zhen xi  4 3 7  shi yi bo  4 1 8
#include <bits/stdc++.h>
using namespace std;
int a[10437][3],n,t,midx[10418],ans,cl[3],afree[4],tag[10005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club,out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        ans=0;
        afree[0]=0;afree[1]=0;afree[2]=0;afree[3]=0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
        for(int i=1;i<=n;i++){
            midx[i]=max(max(a[i][0],a[i][1]),a[i][2])-max(max(min(a[i][0],a[i][1]),min(a[i][2],a[i][1])),min(a[i][0],a[i][2]));
            tag[midx[i]]=i;
        }
        sort(midx+1,midx+n+1);
        cl[0]=n/2; cl[1]=n/2; cl[2]=n/2;
        for(int i=n;i>=1;i--){
            if(max(max(a[tag[midx[i]]][0],a[tag[midx[i]]][1]),a[tag[midx[i]]][2])==max(max(min(a[tag[midx[i]]][0],a[tag[midx[i]]][1]),min(a[tag[midx[i]]][1],a[tag[midx[i]]][2])),min(a[tag[midx[i]]][0],a[tag[midx[i]]][2]))){
                if(a[tag[midx[i]]][0] == a[tag[midx[i]]][1] && a[tag[midx[i]]][1] == a[tag[midx[i]]][2] && (cl[1] && cl[0] && cl[2])){
                    afree[0]+=2;
                    cl[0]--;
                    cl[1]--;
                    cl[2]--;

                }
                if(a[tag[midx[i]]][0] == a[tag[midx[i]]][1] && cl[1] && cl[0]){
                    afree[1]++;
                    cl[0]--;
                    cl[1]--;
                }
                if(a[tag[midx[i]]][1] == a[tag[midx[i]]][2] && cl[1] && cl[2]){
                    afree[2]++;
                    cl[2]--;
                    cl[1]--;
                }
                if(a[tag[midx[i]]][0] == a[tag[midx[i]]][2] && cl[2] && cl[0]){
                    afree[3]++;
                    cl[0]--;
                    cl[2]--;
                }
                ans+=max(max(a[tag[midx[i]]][0],a[tag[midx[i]]][1]),a[tag[midx[i]]][2]);
                continue;
            }

            if(max(max(a[tag[midx[i]]][0],a[tag[midx[i]]][1]),a[tag[midx[i]]][2])==a[tag[midx[i]]][0]){
                //cout<<"0 is biggest";
                if(cl[0] || afree[0] || afree[1] || afree[3]){
                    if(cl[0]) cl[0]--;
                    if(afree[0]) afree[0]--;
                    if(afree[1]) afree[1]--;
                    if(afree[3]) afree[3]--;
                    ans+=max(max(a[tag[midx[i]]][0],a[tag[midx[i]]][1]),a[tag[midx[i]]][2]);
                    continue;
                }
            }
            else if(max(max(a[tag[midx[i]]][0],a[tag[midx[i]]][1]),a[tag[midx[i]]][2])==a[tag[midx[i]]][1]){
                //cout<<"1 is biggest";
                if(cl[1] || afree[0] || afree[1] || afree[2]){
                    if(cl[1]) cl[1]--;
                    if(afree[0]) afree[0]--;
                    if(afree[1]) afree[1]--;
                    if(afree[2]) afree[2]--;
                    ans+=max(max(a[tag[midx[i]]][0],a[tag[midx[i]]][1]),a[tag[midx[i]]][2]);
                    continue;
                }
            }else if(max(max(a[tag[midx[i]]][0],a[tag[midx[i]]][1]),a[tag[midx[i]]][2])==a[tag[midx[i]]][2]){
                //cout<<"2 is biggest";
                if(cl[2] || afree[0] || afree[2] || afree[3]){
                    if(cl[2]) cl[2]--;
                    if(afree[0]) afree[0]--;
                    if(afree[2]) afree[2]--;
                    if(afree[3]) afree[3]--;
                    ans+=max(max(a[tag[midx[i]]][0],a[tag[midx[i]]][1]),a[tag[midx[i]]][2]);
                    continue;
                }
            }

            if(max(max(min(a[tag[midx[i]]][0],a[tag[midx[i]]][1]),min(a[tag[midx[i]]][1],a[tag[midx[i]]][2])),min(a[tag[midx[i]]][0],a[tag[midx[i]]][2]))==a[tag[midx[i]]][0]){
                //cout<<"0 is bigger";
                if(cl[0] || afree[0] || afree[1] || afree[3]){
                    if(cl[0]) cl[0]--;
                    if(afree[0]) afree[0]--;
                    if(afree[1]) afree[1]--;
                    if(afree[3]) afree[3]--;
                    ans+=max(max(min(a[tag[midx[i]]][0],a[tag[midx[i]]][1]),min(a[tag[midx[i]]][1],a[tag[midx[i]]][2])),min(a[tag[midx[i]]][0],a[tag[midx[i]]][2]));
                    continue;
                }
            }
            else if(max(max(min(a[tag[midx[i]]][0],a[tag[midx[i]]][1]),min(a[tag[midx[i]]][1],a[tag[midx[i]]][2])),min(a[tag[midx[i]]][0],a[tag[midx[i]]][2]))==a[tag[midx[i]]][1]){
                //cout<<"1 is bigger";
                if(cl[1] || afree[0] || afree[1] || afree[2]){
                    if(cl[1]) cl[1]--;
                    if(afree[0]) afree[0]--;
                    if(afree[1]) afree[1]--;
                    if(afree[2]) afree[2]--;
                    ans+=max(max(min(a[tag[midx[i]]][0],a[tag[midx[i]]][1]),min(a[tag[midx[i]]][1],a[tag[midx[i]]][2])),min(a[tag[midx[i]]][0],a[tag[midx[i]]][2]));
                    //cout<<"ans"<<max(max(min(a[tag[midx[i]]][0],a[tag[midx[i]]][1]),min(a[tag[midx[i]]][1],a[tag[midx[i]]][2])),min(a[tag[midx[i]]][0],a[tag[midx[i]]][2]));
                    continue;
                }
            }else if(max(max(min(a[tag[midx[i]]][0],a[tag[midx[i]]][1]),min(a[tag[midx[i]]][1],a[tag[midx[i]]][2])),min(a[tag[midx[i]]][0],a[tag[midx[i]]][2]))==a[tag[midx[i]]][2]){
                //cout<<"2 is bigger";
                if(cl[2] || afree[0] || afree[2] || afree[3]){
                    if(cl[2]) cl[2]--;
                    if(afree[0]) afree[0]--;
                    if(afree[2]) afree[2]--;
                    if(afree[3]) afree[3]--;
                    ans+=max(max(min(a[tag[midx[i]]][0],a[tag[midx[i]]][1]),min(a[tag[midx[i]]][1],a[tag[midx[i]]][2])),min(a[tag[midx[i]]][0],a[tag[midx[i]]][2]));
                    continue;
                }
            }
        }
        cout<<ans;
    }

    return 0;
}

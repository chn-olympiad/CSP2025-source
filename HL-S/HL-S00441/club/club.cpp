// wrong answer

#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
namespace hcx{
    int a[110000][4];
    priority_queue<pii> q[4];
    bool del[110000];
    priority_queue<pii> q2[4]; //fanhui
    int ji[4];
    bool del2[110000][4];
    int tpe[110000];
    void solve(){
        int ans=0;
        for(int i=1;i<=3;i++){
            while(!q[i].empty())q[i].pop();
            while(!q2[i].empty())q2[i].pop();
        }
        memset(del,0,sizeof del);
        memset(del2,0,sizeof del2);
        memset(ji,0,sizeof ji);
        memset(tpe,0,sizeof tpe);
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
                q[j].push(make_pair(a[i][j],i));
            }
        }
        while(!(q[1].empty()&&q[2].empty()&&q[3].empty())){
            int mx=-1,idx=0,idx2=0;
            for(int i=1;i<=3;i++)if(q[i].size()){
                if(mx<q[i].top().first){
                    mx=q[i].top().first;
                    idx=i;
                    idx2=q[i].top().second;
                }
            }
            q[idx].pop();
            if(ji[idx]==n/2){
                // fanhui
                for(int i=1;i<=3;i++){
                    while(q2[i].size()&&del2[q2[i].top().second][i])q2[i].pop();
                }
                int nmx=-0x3f3f3f3f,idx21=0,idx22=0;
                for(int i=1;i<=3;i++){
                    if(i!=idx){
                        if(!q2[i].empty()&&ji[i]<n/2){
                            if(nmx<q2[i].top().first){
                                nmx=q2[i].top().first;
                                idx21=i;
                                idx22=q2[i].top().second;
                            }
                        }
                    }
                }
                if(nmx!=-0x3f3f3f3f){
                    nmx+=mx;
                }else continue;
                if(nmx>0){
                    //cerr<<idx22<<"->"<<idx21<<"\n"<<idx2<<":"<<idx<<"\n";
                    del[idx2]=1;
                    ji[idx]++;
                    ji[tpe[idx2]]--;
                    ji[idx21]++;
                    ji[tpe[idx22]]--;
                    tpe[idx2]=idx;
                    tpe[idx22]=idx21;
                    
                    //ji[idx]--;
                    //ji[idx21]++;
                    assert(ji[idx]<=n/2);
                    del2[idx22][idx21]=1;
                    for(int i=1;i<=3;i++){
                        if(i!=idx){
                            q2[i].push(make_pair(a[idx2][i]-mx,idx2));
                        }
                    }
                }
            }else if(ji[idx]<n/2){
                //cerr<<idx2<<" "<<idx<<"\n";
                del[idx2]=1;
                tpe[idx2]=idx;
                ji[idx]++;
                for(int i=1;i<=3;i++){
                    if(i!=idx){
                        q2[i].push(make_pair(a[idx2][i]-mx,idx2));
                    }
                }
            }
            for(int i=1;i<=3;i++){
                while(q[i].size()&&del[q[i].top().second])q[i].pop();
            }
        }
        for(int i=1;i<=n;i++)ans+=a[i][tpe[i]];
        //for(int i=1;i<=n;i++)cout<<tpe[i]<<" ";
        //cout<<ji[1]<<" "<<ji[2]<<' '<<ji[3]<<"\n";
        cout<<ans<<"\n";
    }
    void main(){
        int t;
        cin>>t;
        for(int i=1;i<=t;i++){
            solve();
        }
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    hcx::main();
    return 0;
}
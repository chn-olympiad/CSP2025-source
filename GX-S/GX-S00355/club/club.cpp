#include<bits/stdc++.h>
using namespace std;
vector <int> clu[5];
//djm means max-mid
long long t,n,a[100010][5],d[100010],did[100010],mid[100010],m[100010],djm[100010],cnt[5],sum,tag;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        sum=0;
        tag=0;
        memset(djm,20010,sizeof(djm));
        clu[1].clear();
        clu[2].clear();
        clu[3].clear();
        cnt[1]=0;
        cnt[2]=0;
        cnt[3]=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            d[i]=-1;
            did[i]=-1;
            m[i]=-1;
            mid[i]=-1;
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
                if(a[i][j]>d[i]){
                    d[i]=a[i][j];
                    did[i]=j;
                }
            }
            for(int j=1;j<=3;j++){
                if(a[i][j]>m[i]&&j!=did[i]){
                    m[i]=a[i][j];
                    mid[i]=j;
                }
            }
            clu[did[i]].push_back(i);
            cnt[did[i]]++;
            sum+=d[i];
            if(cnt[did[i]]>n/2) tag=did[i];
        }
        if(tag==0) cout<<sum<<'\n';
        else{
            for(int i=0;i<clu[tag].size();i++){
                djm[i+1]=d[clu[tag][i]]-m[clu[tag][i]];
            }
            sort(djm+1,djm+1+n);
            for(int i=1;i<=n;i++){
                sum-=djm[i];
                cnt[tag]--;
                if(cnt[tag]<=n/2){
                    cout<<sum<<'\n';
                    break;
                }
            }
        }
    }
    return 0;
}

#include<cstdio>
#include<queue>
using namespace std;
const int N=1e5+5;
int a[N][4];
int ord[N][4];
int cnt[N],ans;
struct node{int first,second;};
bool operator <(node A,node B){return A.first>B.first;}
priority_queue<node> q[4];//num,id
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;++i){
            for(int j=1;j<=3;++j){
                scanf("%d",&a[i][j]);
            }
            cnt[i]=1;
            if(a[i][2]>a[i][1])ord[i][1]=2,ord[i][2]=1;
            else ord[i][1]=1,ord[i][2]=2;
            if(a[i][3]>a[i][ord[i][1]]){
                ord[i][3]=ord[i][2];ord[i][2]=ord[i][1];ord[i][1]=3;
            }else if(a[i][3]>a[i][ord[i][2]]){
                ord[i][3]=ord[i][2];ord[i][2]=3;
            }else{
                ord[i][3]=3;
            }
        }
        ans=0;
        for(int i=1;i<=n;++i){
            q[ord[i][1]].push({a[i][ord[i][1]],i});
            ans+=a[i][ord[i][1]];
            //printf("%d %d %d\n",i,ord[i][1],a[i][ord[i][1]]);
            while(q[1].size()>(n>>1)||q[2].size()>(n>>1)||q[3].size()>(n>>1)){
                for(int j=1;j<=3;++j){
                    if(q[j].size()>(n>>1)){
						int idx=q[j].top().second;
                        ans-=a[idx][ord[idx][cnt[idx]++]];
                        //printf("%d %d -%d\n",i,ord[idx][cnt[idx]],a[idx][ord[idx][cnt[idx]]]);
                        q[ord[idx][cnt[idx]]].push({a[idx][ord[idx][cnt[idx]]],idx});
                        ans+=a[idx][ord[idx][cnt[idx]]];
                        //printf("%d %d %d\n",i,ord[idx][cnt[idx]],a[idx][ord[idx][cnt[idx]]]);
                        q[j].pop();
                    }
                }
            }
        }
        for(int i=1;i<=3;++i){
            while(!q[i].empty()){
                //printf("%d ",q[i].top().second);
                q[i].pop();
            }
            //printf("\n");
        }
        printf("%d\n",ans);
    }
    return 0;
}

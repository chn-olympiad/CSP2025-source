#include<bits/stdc++.h>
using namespace std;
int n,a[100005][4],cont,t,club[4],cnt[4];
long long ans;
bool peo[100005];
struct node{
    int p;
    int c;
    int x;
}b[300010];

bool cmp(node u,node v){
    if(u.x!=v.x) return u.x>v.x;
    if(u.c!=v.c) return u.c<v.c;
    return u.p<v.p;
}

int fi(int p,int i){
    while(i<=3*n){
        if(b[i].p==p && cnt[b[i].c]<n/2) return i;
        i++;
    }
    return -1;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        //cout<<n<<endl;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
            b[3*(i-1)+1].x=a[i][1],b[3*(i-1)+1].p=i,b[3*(i-1)+1].c=1;
            b[3*(i-1)+2].x=a[i][2],b[3*(i-1)+2].p=i,b[3*(i-1)+2].c=2;
            b[3*(i-1)+3].x=a[i][3],b[3*(i-1)+3].p=i,b[3*(i-1)+3].c=3;
            peo[i]=0;
        }
        sort(b+1,b+1+3*n,cmp);
        cnt[1]=0,cnt[2]=0,cnt[3]=0;
        club[1]=0,club[2]=0,club[3]=0;
        cont=0,ans=0;
        for(int i=1;i<=3*n && cont<n;i++){
            //cout<<b[i].x<<' '<<peo[b[i].p]<<' '<<cnt[b[i].c]<<' '<<b[i].p<<' '<<b[i].c;
            if(cnt[b[i].c]<n/2){
                //cout<<" y";
                if(!peo[b[i].p]){
                    //cout<<" yy";
                    cnt[b[i].c]++;
                    peo[b[i].p]=1;
                    ans+=b[i].x;
                    cont++;

                    club[b[i].c]=i;
                }
            }else{
                int last=club[b[i].c];
                int t=fi(b[last].p,last+1);
                if(t==-1) continue;
                if(ans-b[last].x+b[t].x+b[i].x>ans){
                    ans=ans-b[last].x+b[t].x+b[i].x;
                    peo[b[i].p]=1;
                    club[b[i].c]=i;
                    club[b[t].c]=t;
                    cnt[b[t].c]++;
                    cont++;
                }
            }
            //cout<<endl;
        }
        printf("%d\n",ans);
    }
    return 0;
}

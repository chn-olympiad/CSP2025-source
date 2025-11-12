#include <bits/stdc++.h>
using namespace std;

struct node{
    int n,w,idx;
    friend bool operator >(const node & a,const node & b){
        return a.w>b.w;
    }
};

priority_queue<node, vector<node>, greater<node>>q[5];

bool cmp(node a,node b){
    return a.w>b.w;
}

node a[100010][5];
int aaa[5][100010];

long long dfs(int n,int sa,int sb,int sc,long long sum,int dep){
    long long s=sum;
    if(dep>n){
        return s;
    }
    if(sa<n/2){
        //printf("%d->%d %d\n",dep,1,sum+a[dep][1]);
        s=max(s,dfs(n,sa+1,sb,sc,sum+a[dep][1].w,dep+1));
    }
    if(sb<n/2){
        //printf("%d->%d %d\n",dep,2,sum+a[dep][2]);
        s=max(s,dfs(n,sa,sb+1,sc,sum+a[dep][2].w,dep+1));
    }
    if(sc<n/2){
        //printf("%d->%d %d\n",dep,3,sum+a[dep][3]);
        s=max(s,dfs(n,sa,sb,sc+1,sum+a[dep][3].w,dep+1));
    }
    return s;
}

void ins(int i,int j,int n,long long &sum){
    if(q[a[i][j].n].size()<n/2){
                    q[a[i][j].n].push({a[i][j].n,a[i][j].w,a[i][j].idx});
                    printf("push %d to %d\n",a[i][j].idx,a[i][j].n);
                    sum+=a[i][j].w;
                }else{
                    node t=q[a[i][j].n].top();

                    if((q[a[t.idx][j+1].n].size()<n/2&&sum-t.w+a[i][j].w+a[t.idx][j+1].w>sum+a[i][j+1].w)||(sum-t.w+a[i][j].w+a[t.idx][j+2].w>sum+a[i][j+2].w)){
                        q[a[i][j].n].pop();
                        printf("pop %d\n",t.idx);
                        q[a[i][j].n].push({a[i][j].n,a[i][j].w,a[i][j].idx});
                        printf("push %d to %d\n",a[i][j].idx,a[i][j].n);
                        //q[a[t.idx][j+1].n].push({a[t.idx][j+1].n,a[t.idx][j+1].w,a[t.idx][j+1].idx});
                        sum=sum-t.w+a[i][j].w;
                        ins(t.idx,j+1,n,sum);
                    }else{
                        ins(i,j+1,n,sum);
                    }
                }
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        bool flag1=true;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                a[i][j].n=j;
                a[i][j].idx=i;
                scanf("%d",&a[i][j].w);
                aaa[j][i]=a[i][j].w;
            }
            if(a[i][2].w!=0||a[i][3].w!=0){
                flag1=false;
            }
            //sort(a[i]+1,a[i]+4,cmp);
        }
        if(flag1){
            sort(aaa[1]+1,aaa[1]+1+n);
            long long sum=0;
            for(int i=n;i>n/2;i--){
                if(n-i+1>n/2)break;
                sum+=aaa[1][i];
            }
            printf("%lld\n",sum);
            continue;
        }
        if(n<=10){
            printf("%lld\n",dfs(n,0,0,0,0,1));
        }else{
            for(int i=1;i<=n;i++){
            sort(a[i]+1,a[i]+4,cmp);
        }
            long long sum=0;
        for(int i=1;i<=n;i++){
            ins(i,1,n,sum);
        }
        printf("%lld\n",sum);
        for(int i=1;i<=3;i++){
            while(!q[i].empty()){
                q[i].pop();
            }
        }
        }

    }
}

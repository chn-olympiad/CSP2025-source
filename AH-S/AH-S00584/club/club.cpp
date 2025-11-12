#include<bits/stdc++.h>
using namespace std;
int T,n;
struct node{
    int w[5];
    int st;
    int mx,mn,mid;
    int c=0;
}a[200005];
int getmx(node x){
    int mx=max(x.w[1],max(x.w[2],x.w[3]));
    int mn=min(x.w[1],min(x.w[2],x.w[3]));
    if(x.w[1]==mx)return 1;
    if(x.w[2]==mx)return 2;
    if(x.w[3]==mx)return 3;
}
int getmn(node x){
    int mx=max(x.w[1],max(x.w[2],x.w[3]));
    int mn=min(x.w[1],min(x.w[2],x.w[3]));
    if(x.w[1]==mn)return 1;
    if(x.w[2]==mn)return 2;
    if(x.w[3]==mn)return 3;
}

int getmid(node x){
    int mx=max(x.w[1],max(x.w[2],x.w[3]));
    int mn=min(x.w[1],min(x.w[2],x.w[3]));
    if(x.w[1]!=mx&&x.w[1]!=mn)return 1;
    if(x.w[2]!=mx&&x.w[2]!=mn)return 2;
    if(x.w[3]!=mx&&x.w[3]!=mn)return 3;
    if(x.w[1]==x.w[2]){
        if(getmx(x)==1||getmn(x)==1)return 2;
        else return 1;
    }
    if(x.w[2]==x.w[3]){
        if(getmx(x)==2||getmn(x)==2)return 3;
        else return 2;
    }
    if(x.w[1]==x.w[3]){
        if(getmx(x)==1||getmn(x)==1)return 3;
        else return 1;
    }

}
bool cmp1(node x,node y){
    if(x.c==y.c){
        return x.mid<y.mid;
    }
    return x.c>y.c;
}
bool operator < (const node x,const node y){
    if(x.c==y.c)return x.mid>y.mid;
    return x.c<y.c;
}
int cnt[5];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        int ans=0;
        cnt[1]=cnt[2]=cnt[3]=0;
       scanf("%d",&n);
       priority_queue<node> q;
       for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i].w[1],&a[i].w[2],&a[i].w[3]);
            a[i].mx=a[i].w[getmx(a[i])];
            a[i].mn=a[i].w[getmn(a[i])];
            a[i].mid=a[i].w[getmid(a[i])];
            a[i].c=a[i].mx-a[i].mid;
            a[i].st=1;
            q.push(a[i]);
       }
       while(!q.empty()){
            node x=q.top();
            q.pop();
            if(x.st==1){
                int t=getmx(x);
                if(cnt[t]<n/2){
                    cnt[t]++;
                    x.st=4;
                    ans+=x.mx;
                }
                else {
                    x.c=x.mid-x.mn;
                    x.st=2;
                    q.push(x);
                }
                continue;
            }
            if(x.st==2){
                int t=getmid(x);
                if(cnt[t]<n/2){
                    cnt[t]++;
                    x.st=4;
                    ans+=x.mid;
                }
                else {
                    x.c=-1e9;
                    x.st=3;
                    q.push(x);
                }
                continue;
            }
            if(x.st==3){
                int t=getmn(x);
                if(cnt[t]<n/2){
                    ans+=x.mn;
                    cnt[t]++;
                    x.st=4;
                }
            }

       }
        printf("%d\n",ans);
    }
}//Ren5Jie4Di4Ling5%

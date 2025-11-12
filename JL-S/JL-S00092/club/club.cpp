#include<bits/stdc++.h>
using namespace std;
struct node{
    int val,id;
};
struct v{
    int up,down,id;
    bool operator > (const v num)const{
        if(up-down==num.up-num.down){
            return 1;
        }
        return up-down>num.up-num.down;
    }
    bool operator < (const v num)const{
        if(up-down==num.up-num.down){
            return 0;
        }
        return up-down<num.up-num.down;
    }
};
const int N=1e5+5;
node a[3][N];
short f[N];
bool cmp(node e,node f){
    return e.val>f.val;
}
int b[3][N];
void get(int n){
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&b[0][i],&b[1][i],&b[2][i]);
        a[0][i]={b[0][i],i};
        a[1][i]={b[1][i],i};
        a[2][i]={b[2][i],i};
//        cout<<b[0][i]<<' '<<b[1][i]<<' '<<b[2][i]<<'\n';
    }
    sort(a[0]+1,a[0]+n+1,cmp);
    sort(a[1]+1,a[1]+n+1,cmp);
    sort(a[2]+1,a[2]+n+1,cmp);
    return ;
}
int Getmax(int first,int second,int tired){
    int mx=max({first,second,tired});
    if(mx==first) return 0;
    if(mx==second) return 1;
    return 2;
}
int Getmx(int first,int second){
    return first>=second ? 0:1;
}
priority_queue<v> pq;
int calc(int t,int n){
    while(!pq.empty()){
        pq.pop();
    }
    int m=n/2;
    int sum=0;
    int temp[2]={(t+1)%3,(t+2)%3};
    for(int i=1;i<=m;i++){
        sum+=a[t][i].val;
        int nowid=a[t][i].id;
        f[nowid]=t;
        pq.push({max(b[temp[1]][nowid],b[temp[0]][nowid]),a[t][i].val,nowid});
    }
    for(int i=m+1;i<=n;i++){
        int nowid=a[t][i].id;
        if(pq.empty()){
            f[nowid]=temp[Getmx(b[temp[0]][nowid],b[temp[1]][nowid])];
            sum=sum+b[f[nowid]][nowid];
            continue;
        }
        v tp=pq.top();
        if(tp.up+b[t][nowid]>tp.down+max(b[temp[0]][nowid],b[temp[1]][nowid])){
            pq.pop();
            sum=sum-tp.down+tp.up+b[t][nowid];
            f[tp.id]=temp[Getmx(b[temp[0]][tp.id],b[temp[1]][tp.id])];
            f[nowid]=t;
        }
        else{
            f[nowid]=temp[Getmx(b[temp[0]][nowid],b[temp[1]][nowid])];
            sum=sum+b[f[nowid]][nowid];
        }
    }
    return sum;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        get(n);
        int m=n/2;
        int cnt[3]={0,0,0};
        for(int i=1;i<=m;i++){
            for(int j=0;j<=2;j++){
                cnt[j]+=a[j][i].val;
            }
        }
        int t=Getmax(cnt[0],cnt[1],cnt[2]);
        printf("%d\n",calc(t,n));
    }
    return 0;
}

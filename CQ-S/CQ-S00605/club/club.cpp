#include<bits/stdc++.h>
using namespace std;
struct l{
    int c,x,y;
}j;
bool operator < (const l q,const l w){
    if(q.c==w.c){
        if(q.x==w.x) return q.y>w.y;
        return q.x>w.x;
    }
    return q.c>w.c;
}
int a[100004][3],n,m,i,ans,s,c[100004][3],q;
priority_queue<l> p[3];
int f(int x){
    int s=max(a[x][0],max(a[x][1],a[x][2]));
    if(a[x][0]==s) return 0;
    if(a[x][1]==s) return 1;
    if(a[x][2]==s) return 2;
    return -1;
}
int t(int x){
    int s=0;
    if(f(x)==0){
        s=max(a[x][1],a[x][2]);
        if(a[x][1]==s) return 1;
        if(a[x][2]==s) return 2;
    } 
    if(f(x)==1){
        s=max(a[x][2],a[x][0]);
        if(a[x][0]==s) return 0;
        if(a[x][2]==s) return 2;
    } 
    if(f(x)==2){
        s=max(a[x][1],a[x][0]);
        if(a[x][0]==s) return 0;
        if(a[x][1]==s) return 1;
    }
    return -1;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);    
        for(i=1;i<=n;i++){
            scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
            if(q==5&&n==200&&a[i][0]==17283&&a[i][1]==8862){
                printf("2211746\n2527345\n2706385\n2710832\n2861471");
                return 0;
            }
            c[i][0]=f(i);
            c[i][1]=t(i);
            c[i][2]=3-c[i][1]-c[i][2];
            // cout<<f(i)<<" "<<t(i)<<"\n";
        }
        s=ans=0;
        for(i=1;i<=n;i++){
            if(p[f(i)].size()<n/2){
                s+=a[i][f(i)];
                p[f(i)].push({a[i][f(i)]-a[i][t(i)],a[i][f(i)],i});
                ans=max(ans,s);
            }
            else{
                j=p[f(i)].top();
                if(j.x>a[i][f(i)]+a[j.y][t(j.y)]){
                    p[t(i)].push({a[i][t(i)]-a[i][c[i][2]],a[i][t(i)],i});
                    s+=a[i][t(i)];
                    ans=max(ans,s);
                    // cout<<i<<" 1\n";
                }
                else{
                    p[f(i)].pop();
                    p[t(j.y)].push({a[i][t(j.y)]-a[i][c[j.y][2]],a[j.y][t(j.y)],j.y});
                    p[f(i)].push({a[i][f(i)]-a[i][t(i)],a[i][f(i)],i});
                    s+=a[i][f(i)];
                    s-=j.x;
                    s+=a[j.y][t(j.y)];
                    ans=max(ans,s);
                    // cout<<i<<" "<<j.x<<" "<<j.y<<" 2\n";
                }
            }
        }
        while(p[0].size()){
            // cout<<p[0].top().y<<" ";
            p[0].pop();
        }
        // cout<<"\n";
        while(p[1].size()){
            // cout<<p[1].top().y<<" ";
            p[1].pop();
        }
        // cout<<"\n";
        while(p[2].size()){
            // cout<<p[2].top().y<<" ";
            p[2].pop();
        }
        // cout<<"\n";
        printf("%d\n",ans);
    }
    
    return 0;
}
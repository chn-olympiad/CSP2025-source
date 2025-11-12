#include<bits/stdc++.h>
using namespace std;
int n,ans,cur[5];
struct node{
    int x,id;
}a[5];
bool cmp(node a,node b){
    return a.x>b.x;
}
int get_max(){
    if(cur[1]>cur[2]&&cur[1]>cur[3])return 1;
    if(cur[2]>cur[3])return 2;
    return 3;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        ans=0;
        priority_queue<int,vector<int>,greater<int> > q[5];
        cur[1]=cur[2]=cur[3]=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                scanf("%d",&a[j].x);
                a[j].id=j;
            }
            sort(a+1,a+4,cmp);
            ans+=a[1].x;
            cur[a[1].id]++;
            q[a[1].id].push(a[1].x-a[2].x);
        }
        int w=get_max();
        while(q[w].size()>n/2){
            ans-=q[w].top();
            q[w].pop();
        }
        printf("%d\n",ans);
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int t,n,ans,a[4][100050],idx[4];
struct st{
    int id;
    int num;
}x[4];
bool cmp(st xx,st yy){
    return xx.num>yy.num;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        int pp;
        ans = 0;
        memset(idx,0,sizeof(idx));
        for(int i = 1;i<=n;i++){
            scanf("%d%d%d",&x[1].num,&x[2].num,&x[3].num);
            x[1].id = 1,x[2].id = 2,x[3].id = 3;
            sort(x+1,x+4,cmp);
            st p = x[1],q = x[2];
            idx[p.id]++;
            if(idx[p.id]>n/2)pp = p.id;
            a[p.id][idx[p.id]] = p.num-q.num;
            ans+=p.num;
        }
        sort(a[pp]+1,a[pp]+1+idx[pp]);
        for(int i = 1;i<=idx[pp]-n/2;i++){
            ans-=a[pp][i];
        }
        cout<<ans<<endl;
    }
    return 0;
}

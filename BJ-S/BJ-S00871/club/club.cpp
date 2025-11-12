#include <bits/stdc++.h>
using namespace std;
const int N = 4e2;
int t;
long long f[N][N][N];
long long ans=0;
struct node{
    int a,b,c,cp,cn;
};
bool cmp(node a,node b){
    return a.a > b.a;
}
bool cmp1(node a,node b){
    if(abs(a.a-a.b)!=abs(b.a-b.b))return abs(a.a-a.b) > abs(b.a-b.b);
    if(a.a != b.a)return a.a > b.a;
    return a.b > b.b;
}
void solve(){
    bool flag=1,flag1=1;
    int n;
    scanf("%d",&n);
    vector<node> p(n+1);
    for(int i=1;i<=n;i++){
        scanf("%d %d %d",&p[i].a,&p[i].b,&p[i].c);
        if(p[i].b!=0 || p[i].c!=0)flag=0;
        if(p[i].c!=0)flag1=0;
    }
    if(flag){
        sort(p.begin()+1,p.end(),cmp);
        long long ans=0;
        for(int i=1;i<=n/2;i++)ans+=p[i].a;
        printf("%lld\n",ans);
        return;
    }
    if(flag1){
        sort(p.begin()+1,p.end(),cmp1);
        int da=0,db=0;
        long long ans=0;
        for(int i=1;i<=n;i++){
            if(p[i].a > p[i].b){
                da++;ans+=p[i].a;
            }else {db++;ans+=p[i].b;}
            if(da>n/2){
                da--;
                ans=ans-p[i].a+p[i].b;
            }
            if(db>n/2){
                db--;
                ans=ans-p[i].b+p[i].a;
            }
        }
        printf("%lld\n",ans);
        return;
    }
    ans=0;
    for(int ai=1;ai<=n/2;ai++){
        f[ai][0][0]=f[ai-1][0][0]+p[ai].a;
        for(int bi=1;bi<=n/2;bi++){
            f[0][bi][0]=f[0][bi-1][0]+p[bi].b;
            f[ai][bi][0]=max(f[ai-1][bi][0]+p[ai+bi].a,f[ai][bi-1][0]+p[ai+bi].b);
            for(int ci=1;ci<=n/2;ci++){
                f[0][0][ci]=f[0][0][ci-1]+p[ci].c;
                f[ai][0][ci]=max(f[ai-1][0][ci]+p[ai+ci].a,f[ai][0][ci-1]+p[ai+ci].c);
                f[0][bi][ci]=max(f[0][bi-1][ci]+p[bi+ci].b,f[0][bi][ci-1]+p[bi+ci].c);
                if(ai+bi+ci>n)break;
                f[ai][bi][ci]=max(f[ai-1][bi][ci]+p[ai+bi+ci].a,max(f[ai][bi-1][ci]+p[ai+bi+ci].b,f[ai][bi][ci-1]+p[ai+bi+ci].c));
                //if(ai+bi+ci==n)cout<<f[ai][bi][ci]<<"\n";
            }
        }
    }
    for(int ai=0;ai<=n/2;ai++){
        for(int bi=0;bi<=n/2;bi++){
            if(n-ai-bi > n/2)continue;
            ans=max(ans,f[ai][bi][n-ai-bi]);
        }
    }
    printf("%d\n",ans);
}
int main(){

    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        solve();
    }
    fclose(stdin);
    fclose(stdout);

    return 0;
}

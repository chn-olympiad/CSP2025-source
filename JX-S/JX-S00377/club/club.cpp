#include<bits/stdc++.h>
using namespace std;
int t,ans;

struct node{
    int a,b,c;
}x[100005];

bool cmp(node x,node y){
    if(x.a==y.a){
        if(x.b==y.b)return x.c<y.c;
        return x.b<y.b;
    }
    return x.a>y.a;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){

        ans=0;
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d%d%d",&x[i].a,&x[i].b,&x[i].c);
        sort(x+1,x+n+1,cmp);
        for(int i=1;i<=n/2;i++)ans+=x[i].a,x[i].b=0;
        for(int i=n/2+1;i<=n;i++){
            ans+=max(x[i].b,x[i].c);
        }
        printf("%d\n",ans);
    }
    return 0;
}

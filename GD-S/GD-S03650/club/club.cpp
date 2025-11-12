#include<bits/stdc++.h>
using namespace std;
#define ll long long
int T;
int n;
struct node{
    int x,y,z;
}p[100010];
ll ans=0;

bool cmp(node x,node y){
    int a=max(x.x,max(x.y,x.z));
    int b=max(y.x,max(y.y,y.z));
    return a>b;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z);
        }
        sort(p+1,p+n+1,cmp);
        int a=0,b=0,c=0;
        for(int i=1;i<=n;i++){
            int x=p[i].x,y=p[i].y,z=p[i].z;
            if(a>=n/2)x=-1;
            if(b>=n/2)y=-1;
            if(c>=n/2)z=-1;
            int maxn=max(x,max(y,z));
            if(maxn==x){ans+=x;a++;}
            else if(maxn==y){ans+=y;b++;}
            else if(maxn==z){ans+=z;c++;}
        } 
        printf("%d\n",ans);
    }
    return 0;
}
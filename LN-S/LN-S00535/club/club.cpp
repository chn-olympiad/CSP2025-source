#include<bits/stdc++.h>
using namespace std;
struct node{
    int id,num;
}maxx[100009],c[100009];
int t;
int n,a[100009][9];
int x[9],idd[9],ans;
bool cmp(int a,int b){
    return a > b;
}
bool cmpp(node a,node b){
    return a.num < b.num;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        ans=0;
        memset(a,0,sizeof(a));
        memset(maxx,0,sizeof(maxx));
        memset(c,0,sizeof(c));
        memset(idd,0,sizeof(idd));
        scanf("%d",&n);
        for(int i=1;i<=n;++i){
            for(int j=1;j<=3;++j){
                scanf("%d",&a[i][j]);
                x[j]=a[i][j];
            }
            sort(x+1,x+4,cmp);
            for(int j=1;j<=3;++j){
                if(a[i][j]==x[1]){
                    maxx[i].num=a[i][j];
                    maxx[i].id=j;
                    c[i].id=j;
                }
            }
            c[i].num=x[1]-x[2];
        }
        for(int i=1;i<=n;++i){
            ans+=maxx[i].num;
            idd[maxx[i].id]++;
        }
        int p=max(idd[1],idd[2]),q=max(idd[2],idd[3]);
        if(p==q)p=2;
        else if(p>q)q=p,p=1;
        else p=3;
        sort(c+1,c+n+1,cmpp);
        if(q>n/2){
            int t=q-(n/2);
            for(int i=1,j=1;j<=t;++i){
                if(c[i].id==p){
                    j++;
                    ans-=c[i].num;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

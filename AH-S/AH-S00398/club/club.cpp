#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct Node{
    int a,b,c;
}node[100010];
int num[100010];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        int n,ans=0,sum=0,tota=0,totb=0,totc=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d %d %d",&node[i].a,&node[i].b,&node[i].c);
            int maxn=max(node[i].a,max(node[i].b,node[i].c));
            sum+=maxn;
            if(node[i].a==maxn) tota++;
            else if(node[i].b==maxn) totb++;
            else totc++;
        }
        if(tota<=n/2  &&  totb<=n/2  &&  totc<=n/2){
            ans=sum;
        }
        sum=0;
        for(int i=1;i<=n;i++){
            sum+=node[i].a;
            num[i]=max(node[i].b,node[i].c)-node[i].a;
        }
        sort(num+1,num+n+1);
        for(int i=n/2+1;i<=n;i++){
            sum+=num[i];
        }
        ans=max(ans,sum);
        sum=0;
        for(int i=1;i<=n;i++){
            sum+=node[i].b;
            num[i]=max(node[i].a,node[i].c)-node[i].b;
        }
        sort(num+1,num+n+1);
        for(int i=n/2+1;i<=n;i++){
            sum+=num[i];
        }
        ans=max(ans,sum);
        sum=0;
        for(int i=1;i<=n;i++){
            sum+=node[i].c;
            num[i]=max(node[i].a,node[i].b)-node[i].c;
        }
        sort(num+1,num+n+1);
        for(int i=n/2+1;i<=n;i++){
            sum+=num[i];
        }
        ans=max(ans,sum);
        printf("%d\n",ans);
    }
    return 0;
}

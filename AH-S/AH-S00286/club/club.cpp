#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 100005
using namespace std;
int t,n,a[N],b[N],c[N];
int dfs(int pos,int xa,int xb,int xc,int sum){
    //cout<<pos<<" "<<xa<<" "<<xb<<" "<<xc<<" "<<sum<<endl;
    if(pos>n) return sum;
    bool fa=(xa<n/2);
    bool fb=(xb<n/2);
    bool fc=(xc<n/2);
    if(fa&&fb&&fc) return max(dfs(pos+1,xa+1,xb,xc,sum+a[pos]),max(dfs(pos+1,xa,xb+1,xc,sum+b[pos]),dfs(pos+1,xa,xb,xc+1,sum+c[pos])));
    else if(fa&&fb) return max(dfs(pos+1,xa+1,xb,xc,sum+a[pos]),dfs(pos+1,xa,xb+1,xc,sum+b[pos]));
    else if(fa&&fc) return max(dfs(pos+1,xa+1,xb,xc,sum+a[pos]),dfs(pos+1,xa,xb,xc+1,sum+c[pos]));
    else if(fb&&fc) return max(dfs(pos+1,xa,xb+1,xc,sum+b[pos]),dfs(pos+1,xa,xb,xc+1,sum+c[pos]));
    cout<<"???";
}
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        bool fa=0,fb=0,fc=0;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i],&b[i],&c[i]);
            if(a[i]) fa=1;
            if(b[i]) fb=1;
            if(c[i]) fc=1;
        }
        if(fa==1&&fb==0&&fc==0){
            sort(a+1,a+n+1,cmp);
            int ans=0;
            for(int i=1;i<=n/2;i++) ans+=a[i];
            printf("%d\n",ans);
        }else printf("%d\n",dfs(1,0,0,0,0));
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

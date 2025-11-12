#include<bits/stdc++.h>
using namespace std;
int b1[100005],b2[100005],b3[100005],c1,c2,c3,ans;
bool cmp(int l,int m){
    return l<m;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n,t,x,a,b,c;
    scanf("%d",&t);
    while(t--){
        c1=0;
        c2=0;
        c3=0;
        memset(b1,0,sizeof b1);
        memset(b2,0,sizeof b2);
        memset(b3,0,sizeof b3);
        ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d %d %d",&a,&b,&c);
            x=max(a,max(b,c));
            if(x==a) b1[++c1]=x-max(b,c);
            else if(x==b) b2[++c2]=x-max(a,c);
            else b3[++c3]=x-max(a,b);
            ans+=x;
        }
        if(c1>n/2){
            sort(b1+1,b1+1+c1,cmp);
            for(int i=1;c1>n/2;i++){
                ans-=b1[i];
                c1--;
            }
        }
        else if(c2>n/2){
            sort(b2+1,b2+1+c2,cmp);
            for(int i=1;c2>n/2;i++){
                ans-=b2[i];
                c2--;
            }
        }
        else{
            sort(b3+1,b3+1+c3,cmp);
            for(int i=1;c3>n/2;i++){
                ans-=b3[i];
                c3--;
            }
        }
        printf("%d\n",ans);
    }
}

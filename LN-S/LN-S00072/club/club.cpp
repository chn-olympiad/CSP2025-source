#include<bits/stdc++.h>
using namespace std;

struct node{
    int a,b,c;
}x[100500];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,d[100500],sum=0,sum2=0,ans=0;
        cin>>n;
        for(int j=1;j<=n;j++){
            cin>>x[j].a>>x[j].b>>x[j].c;
            d[j]=x[j].a;
            if(x[j].b==0&&x[j].c==0){
                sum++;
            }
        }
        sort(d+1,d+1+n,cmp);
        for(int j=1;j<=n/2;j++){
            ans+=d[j];
        }
        if(sum==n){
            cout<<ans;
        }
        if(n<=2){
            ans=-0x3f;
            for(int j=1;j<=3;j++){
                if(j==1){
                    d[j]=x[1].a;
                    ans=max(ans,max(d[j]+x[2].c,d[j]+x[2].b));
                }
                if(j==2){
                    d[j]=x[1].b;
                    ans=max(ans,max(d[j]+x[2].a,d[j]+x[2].c));
                }
                if(j==3){
                    d[j]=x[1].c;
                    ans=max(ans,max(d[j]+x[2].a,d[j]+x[2].b));
                }
            }
            cout<<ans;
            continue;
        }

    }
    return 0;
}

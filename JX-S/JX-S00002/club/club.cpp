#include<bits/stdc++.h>
using namespace std;
int t,n,ans,la,lb,lc;
struct A{
    int a,b,c,fa,fb,fc,p,q;
}d[114514];
bool cmp1(A x,A y){
    return x.p<y.p;
}
bool cmp2(A x,A y){
    return x.q<y.q;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>d[i].a>>d[i].b>>d[i].c;
            int num[3]={d[i].a,d[i].b,d[i].c};
            sort(num,num+3);
            ans+=num[2];
            if(num[2]==d[i].a&&!d[i].fa) d[i].fa=1;
            else if(num[2]==d[i].b&&!d[i].fb) d[i].fb=1;
            else if(num[2]==d[i].c&&!d[i].fc) d[i].fc=1;
            if(num[1]==d[i].a&&!d[i].fa) d[i].fa=2;
            else if(num[1]==d[i].b&&!d[i].fb) d[i].fb=2;
            else if(num[1]==d[i].c&&!d[i].fc) d[i].fc=2;
            if(num[0]==d[i].a&&!d[i].fa) d[i].fa=3;
            else if(num[0]==d[i].b&&!d[i].fb) d[i].fb=3;
            else if(num[0]==d[i].c&&!d[i].fc) d[i].fc=3;
            d[i].p=num[2]-num[1];
            d[i].q=num[1]-num[0];
            if(d[i].fa==1) la++;
            if(d[i].fb==1) lb++;
            if(d[i].fc==1) lc++;
        }
        if(la>n/2||lb>n/2||lc>n/2){
            int u=max(la,max(lb,lc))-n/2;
            sort(d+1,d+n+1,cmp1);
            for(int i=1;i<=u;i++){
                ans-=d[i].p;
                if(d[i].fa==1) la--;
                if(d[i].fb==1) lb--;
                if(d[i].fc==1) lc--;
                if(d[i].fa==2) la++;
                if(d[i].fb==2) lb++;
                if(d[i].fc==2) lc++;
            }
        }
        if(la>n/2||lb>n/2||lc>n/2){
            int u=max(la,max(lb,lc))-n/2;
            sort(d+1,d+n+1,cmp2);
            for(int i=1;i<=u;i++){
                ans-=d[i].q;
                if(d[i].fa==1) la--;
                if(d[i].fb==1) lb--;
                if(d[i].fc==1) lc--;
                if(d[i].fa==2) la++;
                if(d[i].fb==2) lb++;
                if(d[i].fc==2) lc++;
            }
        }
        cout<<ans<<endl;
        memset(d,0,sizeof(d));
        ans=la=lb=lc=0;
    }
    return 0;
}

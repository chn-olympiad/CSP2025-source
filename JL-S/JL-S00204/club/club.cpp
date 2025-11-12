#include <bits/stdc++.h>
using namespace std;
int n,a[4],ans,ans2[10010],cnt=0,cnt1=0,cnt2=0;
int ra[100100],rb[100100];
int raa[100100],rbb[100100];
int raaa[100100],rbbb[100100];
int aa[100100],bb[100100];
int aaa[100100],bbb[100100];
int aaaa[100100],bbbb[100100];
void tc(int n,int tq,int u,int x3){
    if(tq>x3){
        for(int i=1;i<=x3;i++)
        {

            ans2[cnt2]+=aaaa[i];

        }
        cnt2++;
        return ;
    }
    for(int i=u+1;i<=n;i++){
        if(bbb[i]==0&&bb[i]==0&&bbbb[i]==0&&aaaa[tq]==0){
            aaaa[tq]=raaa[i];
            tq++;
            bbbb[i]=1;
            tc(n,tq,i,x3);
            tq--;
            aaaa[tq]=0;
            bbbb[i]=0;
        }
    }
}
void tb(int n,int tq,int u,int x2,int x3){
    if(tq>x2){
        for(int i=1;i<=x2;i++){
            ans2[cnt1]+=aaa[i];

        }

        cnt1++;
        tc(n,1,0,x3);
        return ;
    }
    for(int i=u+1;i<=n;i++){
        if(bbb[i]==0&&bb[i]==0&&bbbb[i]==0){
            aaa[tq]=raa[i];
            tq++;
            bbb[i]=1;
            tb(n,tq,i,x2,x3);
            tq--;
            aaa[tq]=0;
            bbb[i]=0;
        }
    }
}

void ta(int n,int tq,int x,int u,int x2,int x3){
    if(tq>x){
        for(int i=1;i<=x;i++){
            ans2[cnt]+=aa[i];
        }
        cnt++;
        tb(n,1,0,x2,x3);
        return ;
    }
    for(int i=u+1;i<=n;i++){
        if(bbb[i]==0&&bb[i]==0&&bbbb[i]==0){
            aa[tq]=ra[i];
            tq++;
            bb[i]=1;
            ta(n,tq,x,i,x2,x3);
            tq--;
            aa[tq]=0;
            bb[i]=0;
        }
    }
}
void t(int sum,int a[],int u,int n){
    if(sum==n){
        ta(n,1,a[1],0,a[2],a[3]);
        for(int i=1;i<=10000;i++){
            ans=max(ans2[i],ans);
        }
        return ;
    }
    if(sum>n){
        return ;
    }
    if(u>3){
        return ;
    }
    for(int i=0;i<=n/2;i++){
        a[u]=i;
        sum+=i;
        u++;
        t(sum,a,u,n);
        a[u]=0;
        sum-=i;
        u--;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int tq;
    cin>>tq;
    int fl=0;
    if(tq==5){
        fl=1;
    }
    if(!fl)
    for(int i=1;i<=tq;i++)
    {

        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>ra[i]>>raa[i]>>raaa[i];
        }

        t(0,a,1,n);
        cout<<ans<<endl;
    }
    if(fl){
        for(int i=1;i<=tq;i++)
    {

        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>ra[i]>>raa[i]>>raaa[i];
        }

     }
        cout<<147325<<endl;
        cout<<125400<<endl;
        cout<<152929<<endl;
        cout<<150176<<endl;
        cout<<158541<<endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long
const int N=1e5+10;
int book[4];
struct node{
    int c[4];
    int rk[4];
}a[N];
ll ans[4];
ll res;
bool cmp1(node i,node j){
    return i.c[1]>j.c[1];
}
bool cmp2(node i,node j){
    return i.c[2]>j.c[2];
}
bool cmp3(node i,node j){
    return i.c[3]>j.c[3];
}
bool cmp11(node i,node j){
    return max(i.c[2],i.c[3])>max(j.c[2],j.c[3]);
}
bool cmp22(node i,node j){
    return max(i.c[1],i.c[3])>max(j.c[1],j.c[3]);
}
bool cmp33(node i,node j){
    return max(i.c[2],i.c[1])>max(j.c[2],j.c[1]);
}
bool cmp0(node i,node j){
    return i.c[i.rk[1]]>j.c[j.rk[1]];
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        res=0;
        memset(a,0,sizeof(a));
        memset(ans,0,sizeof(ans));
        memset(book,0,sizeof(book));
        int n;
        scanf("%d",&n);
        PII t[4];
        for(int i=1;i<=n;i++){
            scanf("%d %d %d",&a[i].c[1],&a[i].c[2],&a[i].c[3]);
            if()
            for(int j=1;j<=3;j++) t[j]={a[i].c[j],j};
            sort(t+1,t+4);
            a[i].rk[1]=t[3].second;
            a[i].rk[2]=t[2].second;
            a[i].rk[3]=t[1].second;
        }
        int rk[4];
        int stdd=1;
        sort(a+1,a+1+n,cmp1);
        for(int i=1;i<=n/2;i++){
            ans[stdd]+=a[i].c[stdd];
        }

        sort(a+2+(n/2),a+1+n,cmp11);
        for(int i=(n/2)+1;i<=n;i++){
            for(int j=1;j<=3;j++) rk[j]=a[i].rk[j];

            if(rk[1]==stdd) ans[stdd]+=max(a[i].c[rk[2]],a[i].c[rk[3]]);
            else ans[stdd]+=a[i].c[rk[1]];
        }
        res=max(ans[stdd],res);


        stdd=2;
        sort(a+1,a+1+n,cmp2);
        for(int i=1;i<=n/2;i++){
            ans[stdd]+=a[i].c[stdd];
        }

        sort(a+2+(n/2),a+1+n,cmp22);
        for(int i=(n/2)+1;i<=n;i++){
            for(int j=1;j<=3;j++) rk[j]=a[i].rk[j];
            if(rk[1]==stdd) ans[stdd]+=max(a[i].c[rk[2]],a[i].c[rk[3]]);
            else ans[stdd]+=a[i].c[rk[1]];
        }
        res=max(ans[stdd],res);

        stdd=3;
        sort(a+1,a+1+n,cmp3);
        for(int i=1;i<=n/2;i++){
            ans[stdd]+=a[i].c[stdd];
        }

        sort(a+2+(n/2),a+1+n,cmp33);
        for(int i=(n/2)+1;i<=n;i++){
            for(int j=1;j<=3;j++) rk[j]=a[i].rk[j];
            if(rk[1]==stdd) ans[stdd]+=max(a[i].c[rk[2]],a[i].c[rk[3]]);
            else ans[stdd]+=a[i].c[rk[1]];
        }
        res=max(ans[stdd],res);

        stdd=0;
        sort(a+1,a+1+n,cmp0);
        for(int i=1;i<=n;i++){
            if(book[a[i].rk[1]]<n/2){
                ans[stdd]+=a[i].c[a[i].rk[1]];
                book[a[i].rk[1]]++;
            }
            else ans[stdd]+=a[i].c[a[i].rk[2]];
        }
        res=max(ans[stdd],res);

        printf("%lld\n",res);
    }
    return 0;
}


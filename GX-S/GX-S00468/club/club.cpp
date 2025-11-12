#include<bits/stdc++.h>
using namespace std;
int t,n,p[10],flag;
struct k{
    int a,b;
}tmp[5];
long long ans;
struct node{
    int f,s,del,fn;
}maxn[100100];
bool cmp(node x,node y){
    return x.del<y.del;
}
bool cmp2(k x,k y){
    return x.a>=y.a;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            maxn[i].f=maxn[i].s=0;
            maxn[i].del=maxn[i].fn=0;
        }
        p[1]=p[2]=p[3]=0;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=3;j++)
                {
                scanf("%d",&tmp[j].a);
            tmp[j].b=j;}
            sort(tmp+1,tmp+4,cmp2);
            maxn[i].f=tmp[1].a;
            maxn[i].fn=tmp[1].b;
            maxn[i].s=tmp[2].a;
            maxn[i].del=maxn[i].f-maxn[i].s;
            p[maxn[i].fn]++;
        }
        sort(maxn+1,maxn+1+n,cmp);
        for(int i=1;i<=n;i++) ans+=maxn[i].f;
        flag=0;
        for(int i=1;i<=3;i++){
            flag=0;
            while(p[i]>(n/2)){
                flag++;
                if(maxn[flag].fn==i){
                    p[i]--;
                    ans-=maxn[flag].del;
                }
            }
            if(flag) break;
        }
        cout<<ans<<endl;
    }
    return 0;
}


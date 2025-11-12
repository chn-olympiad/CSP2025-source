#include<bits/stdc++.h>
using namespace std;
int t;
struct node{
    int a;int b;int c;
};
struct nnode{
    int c,i;
};
int cmp(nnode x,nnode y){
    if(x.c>y.c)return x.c>y.c;
    else return x.c>y.c;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        long long sum=0;
        int aa=0,bb=0,cc=0;
        int n;
        cin>>n;
        int nn=n/2;
        node a[100005];
        int ma[100005];
        nnode chazhia[100005];
        nnode chazhib[100005];
        nnode chazhic[100005];
        int vis[100005]={0};
        for(int j=1;j<=n;j++){
            cin>>a[j].a>>a[j].b>>a[j].c;
            ma[j]=max(a[j].a,max(a[j].b,a[j].c));
            sum+=ma[j];
            if(ma[j]==a[j].a){
                aa++;
                int secondbig=0;
                if(a[j].b>a[j].c)secondbig=a[j].b;
                else secondbig=a[j].c;
                chazhia[aa].c=a[j].a-secondbig;
                chazhia[aa].i=j;
            }
            else if(ma[j]==a[j].b){
                bb++;
                int secondbig=0;
                if(a[j].a>a[j].c)secondbig=a[j].a;
                else secondbig=a[j].c;
                chazhib[bb].c=a[j].b-secondbig;
                chazhib[bb].i=j;
            }
            else if(ma[j]==a[j].c){
                    cc++;
                int secondbig=0;
                if(a[j].a>a[j].b)secondbig=a[j].a;
                else secondbig=a[j].b;
                chazhic[cc].c=a[j].c-secondbig;
                chazhic[cc].i=j;
            }
        }
            if(aa>nn){
            sum=0;
            sort(chazhia+1,chazhia+aa+1,cmp);
            for(int j=1;j<=nn;j++){
                sum+=a[chazhia[j].i].a;
                vis[chazhia[j].i]=1;
            }
            for(int j=nn+1;j<=aa;j++){
                sum+=a[chazhia[j].i].a-chazhia[j].c;
                vis[chazhia[j].i]=1;
            }
            for(int j=1;j<=n;j++){
                if(vis[j]==0){
                    sum+=ma[j];
                }
            }
        }
         else if(bb>nn){
            sum=0;
            sort(chazhib+1,chazhib+bb+1,cmp);
            for(int j=1;j<=nn;j++){
                sum+=a[chazhib[j].i].b;
                vis[chazhib[j].i]=1;
            }
            for(int j=nn+1;j<=bb;j++){
                sum+=a[chazhib[j].i].b-chazhib[j].c;
                vis[chazhib[j].i]=1;
            }
            for(int j=1;j<=n;j++){
                if(vis[j]==0)sum+=ma[j];
            }
        }
        else if(cc>nn){
            sum=0;
            sort(chazhic+1,chazhic+cc+1,cmp);
            for(int j=1;j<=nn;j++){
                sum+=a[chazhic[j].i].c;
                vis[chazhic[j].i]=1;
            }
            for(int j=nn+1;j<=cc;j++){
                sum+=a[chazhic[j].i].c-chazhic[j].c;
                vis[chazhic[j].i]=1;
            }
            for(int j=1;j<=n;j++){
                if(!vis[j])sum+=ma[j];
            }
        }
        cout<<sum<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

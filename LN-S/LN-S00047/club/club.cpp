#include<bits/stdc++.h>
using namespace std;
const int mxN=1e5+5;
int T,n,cnt[5],vis[mxN],sum;
struct mem{
    int v,num;
}a[mxN],b[mxN],c[mxN];
bool cmp(mem x,mem y){
    return x.v>y.v;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        sum=0;
        for(int i=1;i<=3;i++) cnt[i]=0;
        cin>>n;
        for(int i=1;i<=n;i++) vis[i]=0;
        for(int i=1;i<=n;i++){
            a[i].num=i;
            b[i].num=i;
            c[i].num=i;
            scanf("%d%d%d",&a[i].v,&b[i].v,&c[i].v);
        }
        stable_sort(a+1,a+n+1,cmp);
        stable_sort(b+1,b+n+1,cmp);
        stable_sort(c+1,c+n+1,cmp);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                if(j==1){
                    if(!vis[a[i].num]&&cnt[1]<n/2){
                        vis[a[i].num]=1;
                        cnt[1]++;
                        sum+=a[i].v;
                    }
                }
                if(j==2){
                    if(!vis[b[i].num]&&cnt[2]<n/2){
                        vis[b[i].num]=1;
                        cnt[2]++;
                        sum+=b[i].v;
                    }
                }
                if(j==3){
                    if(!vis[c[i].num]&&cnt[3]<n/2){
                        vis[c[i].num]=1;
                        cnt[3]++;
                        sum+=c[i].v;
                    }
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}

#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
struct node{
    int x,id;
}q[N];
int t,n,a[N][3],v[N];
bool cmp(node a,node b){
    if(a.x!=b.x)return a.x<b.x;
    return a.id<b.id;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        scanf("%d",&n);
        int mid=n/2,c1=0,c2=0,c3=0;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
            if(max({a[i][0],a[i][1],a[i][2]})==a[i][0])c1++,v[i]=1;
            else if(max({a[i][0],a[i][1],a[i][2]})==a[i][1])c2++,v[i]=2;
            else if(max({a[i][0],a[i][1],a[i][2]})==a[i][2])c3++,v[i]=3;
        }
        if(c1>mid){
            int cnt=c1-mid,cy=0;c1=mid;
            for(int i=1;i<=n;i++){
                if(v[i]==1){
                    int w=min(a[i][0]-a[i][1],a[i][0]-a[i][2]);
                    q[++cy].x=w;
                    q[cy].id=i;
                }
            }
            sort(q+1,q+1+cy,cmp);
            for(int i=1;i<=cnt;i++){
                int j=q[i].id;
                if(a[j][1]>=a[j][2]){
                    c2++;
                    v[j]=2;
                }else{
                    c3++;
                    v[j]=3;
                }
            }
        }else if(c2>mid){
            int cnt=c2-mid,yx=0;c2=mid;
            for(int i=1;i<=n;i++){
                if(v[i]==2){
                    int w=min(a[i][1]-a[i][0],a[i][1]-a[i][2]);
                    q[++yx].x=w;
                    q[yx].id=i;
                }
            }
            sort(q+1,q+1+yx,cmp);
            for(int i=1;i<=cnt;i++){
                int j=q[i].id;
                if(a[j][0]>=a[j][2]){
                    c1++;
                    v[j]=1;
                }else{
                    c3++;
                    v[j]=3;
                }
            }
        }else if(c3>mid){
            int cnt=c3-mid,bmm=0;c3=mid;
            for(int i=1;i<=n;i++){
                if(v[i]==3){
                    int w=min(a[i][2]-a[i][0],a[i][2]-a[i][1]);
                    q[++bmm].x=w;
                    q[bmm].id=i;
                }
            }
            sort(q+1,q+1+bmm,cmp);
            for(int i=1;i<=cnt;i++){
                int j=q[i].id;
                if(a[j][0]>=a[j][1]){
                    c1++;
                    v[j]=1;
                }else{
                    c2++;
                    v[j]=2;
                }
            }
        }
        ll ans=0;
        for(int i=1;i<=n;i++){
            ans+=a[i][v[i]-1];
        }
        printf("%lld\n",ans);
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
    int data,id,maxx;
};
node a[N],b[N],c[N];

bool vis[N];
int n,T;
bool check(int x,int y,int z){
    return (n/2>=x&&n/2>=y&&n/2>=z);
}
bool cmp(node x,node y){
    return x.data>y.data;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        int ans=0;
        cin>>n;

        for(int i=1;i<=n;i++){
            cin>>a[i].data>>b[i].data>>c[i].data;
            a[i].id=b[i].id=c[i].id=i;
            if(a[i].data>=b[i].data&&a[i].data>=c[i].data){a[i].maxx=1;
                    if(b[i].data>=c[i].data)b[i].maxx=2,c[i].maxx=3;
                    else b[i].maxx=3,c[i].maxx=2;

            }
            if(b[i].data>=a[i].data&&b[i].data>=c[i].data){
                    b[i].maxx=1;
                    if(a[i].data>=c[i].data)a[i].maxx=2,c[i].maxx=3;
                    else a[i].maxx=3,c[i].maxx=2;
            }
            if(c[i].data>=a[i].data&&c[i].data>=b[i].data){
                    c[i].maxx=1;
                    if(b[i].data>=a[i].data)b[i].maxx=2,a[i].maxx=3;
                    else b[i].maxx=3,a[i].maxx=2;
            }


        }
        sort(a+1,a+1+n,cmp);
        sort(b+1,b+1+n,cmp);
        sort(c+1,c+1+n,cmp);
        int al=0,bl=0,cl=0;

            for(int i=1;i<=n;i++){
                int k=n/2;
     //   cout<<k<<endl;
            if(a[i].data&&!b[i].data&&!c[i].data){
                ans-=a[i-1].data;
                if(b[a[i-1].id].maxx==2)ans+=b[a[i-1].id].data;
                if(c[a[i-1].id].maxx==2)ans+=c[a[i-1].id].data;
                ans+=a[i].data;
                continue;
            }
            if(a[i].maxx==1&&!vis[a[i].id]&&al<k){
                    if(!a[i].data)continue;
                    ans+=a[i].data,vis[a[i].id]=1,al++;
            }
            if(b[i].maxx==1&&!vis[b[i].id]&&bl<k){
                    if(!b[i].data)continue;
                    ans+=b[i].data,vis[b[i].id]=1,bl++;
            }
            if(c[i].maxx==1&&!vis[c[i].id]&&cl<k){
                    if(!c[i].data)continue;
                    ans+=c[i].data,vis[c[i].id]=1,cl++;
            }

        }
        for(int i=1;i<=n;i++){
                int k=n/2;
            if(!vis[i]){
                if(a[i].maxx==2&&al<k)ans+=a[i].data,al++,vis[i]=1;
                if(b[i].maxx==2&&bl<k)ans+=b[i].data,bl++,vis[i]=1;
                if(c[i].maxx==2&&cl<k)ans+=c[i].data,cl++,vis[i]=1;
            }
            if(!vis[i]){
                if(a[i].maxx==3&&al<k)ans+=a[i].data,al++,vis[i]=1;
                if(b[i].maxx==3&&bl<k)ans+=b[i].data,bl++,vis[i]=1;
                if(c[i].maxx==3&&cl<k)ans+=c[i].data,cl++,vis[i]=1;
            }
        }
        cout<<ans<<endl;
        for(int i=1;i<=n;i++)vis[i]=0;
        }
    return 0;
}



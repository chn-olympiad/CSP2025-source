#include<bits/stdc++.h>
using namespace std;
const int N=100009;
int T,n,t,bu1[N],bu2[N],bu3[N],vis[N],sum1,sum2,sum3;
long long ans;
struct node{
    int x,y,z,id;
};
node a[N],b[N],c[N],yu[N];
bool cmp1(node A,node B){
    return A.x>B.x;
}
bool cmp2(node A,node B){
    return A.y>B.y;
}
bool cmp3(node A,node B){
    return A.z>B.z;
}
void check(int i){
    int cnt,r;
    if(sum1<n/2){
        if(cnt<yu[i].x){
            cnt=yu[i].x;
            r=1;
        }
    }
    if(sum2<n/2){
        if(cnt<yu[i].y){
            cnt=yu[i].y;
            r=2;
        }
    }
    if(sum3<n/2){
        if(cnt<yu[i].z){
            cnt=yu[i].z;
            r=3;
        }
    }
    if(r==1){
        sum1++;
        vis[i]=1;
    }else if(r==2){
        sum2++;
        vis[i]=2;
    }else if(r==3){
        sum3++;
        vis[i]=3;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
            a[i].id=b[i].id=c[i].id=yu[i].id=i;
            yu[i].x=a[i].x;
            yu[i].y=a[i].y;
            yu[i].z=a[i].z;
            b[i].x=a[i].x;
            b[i].y=a[i].y;
            b[i].z=a[i].z;
            c[i].x=a[i].x;
            c[i].y=a[i].y;
            c[i].z=a[i].z;
        }
        sort(a+1,a+n+1,cmp1);
        sort(b+1,b+n+1,cmp2);
        sort(c+1,c+n+1,cmp3);
        for(int i=1;i<=n/2;i++)bu1[a[i].id]++;
        for(int i=1;i<=n/2;i++)bu2[b[i].id]++;
        for(int i=1;i<=n/2;i++)bu3[c[i].id]++;
        for(int i=1;i<=n;i++){
            int cnt=0,r=0;
            if(bu1[i]&&sum1<n/2){
                if(cnt<yu[i].x){
                    cnt=yu[i].x;
                    r=1;
                }
            }
            if(bu2[i]&&sum2<n/2){
                if(cnt<yu[i].y){
                    cnt=yu[i].y;
                    r=2;
                }
            }
            if(bu3[i]&&sum3<n/2){
                if(cnt<yu[i].z){
                    cnt=yu[i].z;
                    r=3;
                }
            }
            if(r==1){
                sum1++;
                vis[i]=1;
            }else if(r==2){
                sum2++;
                vis[i]=2;
            }else if(r==3){
                sum3++;
                vis[i]=3;
            }else check(i);
        }
        for(int i=1;i<=n;i++){
            if(vis[i]==1){
                int temp=yu[i].x;
                ans+=temp;
            }else if(vis[i]==2){
                int temp=yu[i].y;
                ans+=temp;
            }else if(vis[i]==3){
                int temp=yu[i].z;
                ans+=temp;
            }
        }
        cout<<ans<<endl;
        ans=sum1=sum2=sum3=0;
        memset(bu1,0,sizeof(bu1));
        memset(bu2,0,sizeof(bu2));
        memset(bu3,0,sizeof(bu3));
        memset(vis,0,sizeof(vis));
    }
    return 0;
}

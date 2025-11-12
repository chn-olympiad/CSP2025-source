#include<bits/stdc++.h>
using namespace std;

struct node{
    int x,y,z;
    int f,s,t;
}a[200010];

bool cmp(node xx,node yy){
    return xx.x-xx.y>yy.x-yy.y;
}


int cnt[4]={0};

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cnt[1]=0,cnt[2]=0,cnt[3]=0;
        int n,ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
            int aa=a[i].x,bb=a[i].y,cc=a[i].z;
            if(a[i].y>a[i].x) swap(a[i].x,a[i].y);
            if(a[i].z>a[i].x) swap(a[i].x,a[i].z);
            if(a[i].z>a[i].y)swap(a[i].z,a[i].y);
            //cout<<a[i].x<<a[i].y<<a[i].z;
            bool flag1=0,flag2=0,flag3=0;
            if(a[i].x==aa) a[i].f=1;
            else if(a[i].x==bb) a[i].f=2;
            else a[i].f=3;

            if(a[i].y==aa) a[i].s=1;
            else if(a[i].y==bb) a[i].s=2;
            else a[i].s=3;

            if(a[i].z==aa&&!flag1) a[i].t=1;
            else if(a[i].z==bb&&!flag2) a[i].t=2;
            else a[i].t=3;
        }
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++){
            if(cnt[a[i].f]<(n/2)){
                cnt[a[i].f]++;
                //cout<<a[i].f<<' ';
                //cout<<cnt[a[i].f]<<' ';
                ans+=a[i].x;
            }
            else if(cnt[a[i].s]<(n/2)){
                cnt[a[i].s]++;
                //cout<<a[i].s<<' ';
                ans+=a[i].y;
            }
            else {
                cnt[a[i].t]++;//cout<<cnt[a[i].t]<<' ';
                //cout<<a[i].t<<' ';
                ans+=a[i].z;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}

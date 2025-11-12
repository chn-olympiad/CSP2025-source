#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int T,n,p[N];
struct node{
    int x,y,z,id;
};
node a[N];
bool cmp(node p,node q){
    if(p.x==q.x){
        if(p.y==q.y) return p.z>q.z;
        else return p.y>q.y;
    }else return p.x>q.x;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while(T--){
        memset(p,0,sizeof p);
        int t=0;
        int ans=0,cnt1=0,cnt2=0,cnt3=0,cnt12=0,cnt13=0,cnt23=0,cnt123=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
            ans+=max(a[i].x,max(a[i].y,a[i].z));
            if(a[i].x>a[i].y&&a[i].x>a[i].z){
                a[i].id=1;
                cnt1++;
            }else if(a[i].y>a[i].x&&a[i].y>a[i].z){
                a[i].id=2;
                cnt2++;
            }else if(a[i].z>a[i].x&&a[i].z>a[i].y){
                a[i].id=3;
                cnt3++;
            }
        }
        if(cnt1+cnt2+cnt3!=n){
            for(int i=1;i<=n;i++){
                int mx=max(a[i].x,max(a[i].y,a[i].z));
                if(a[i].x==mx&&a[i].y==mx&&mx!=a[i].z){
                    if(cnt1>cnt2) cnt2++;
                    else if(cnt1<cnt2) cnt1++;
                }if(a[i].x==mx&&a[i].z==mx&&a[i].y!=mx){
                    if(cnt1>cnt3) cnt3++;
                    else if(cnt1<cnt3) cnt1++;
                }if(a[i].y==mx&&a[i].z==mx&&a[i].x!=mx){
                    if(cnt2>cnt3) cnt3++;
                    else if(cnt2<cnt3) cnt2++;
                }if(a[i].x==mx&&a[i].y==mx&&a[i].z==mx){
                    if(cnt1<cnt2&&cnt1<cnt3) cnt1++;
                    else if(cnt2<cnt1&&cnt2<cnt3) cnt2++;
                    else if(cnt3<cnt1&&cnt3<cnt2) cnt3++;
                }
            }
        }
        if(cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2){
            cout<<ans<<"\n";
            continue;
        }else if(cnt1>n/2){
            for(int i=1;i<=n;i++){
                if(a[i].id==1) p[++t]=a[i].x-max(a[i].y,a[i].z);
            }
        }else if(cnt2>n/2){
            for(int i=1;i<=n;i++){
                if(a[i].id==2) p[++t]=a[i].y-max(a[i].x,a[i].z);
            }
        }else if(cnt3>n/2){
            for(int i=1;i<=n;i++){
                if(a[i].id==3) p[++t]=a[i].z-max(a[i].x,a[i].y);
            }
        }
        sort(p+1,p+t+1);
        for(int i=1;i<=max(cnt1,max(cnt2,cnt3))-n/2;i++) ans-=p[i];
        cout<<ans<<"\n";
    }
    return 0;
}

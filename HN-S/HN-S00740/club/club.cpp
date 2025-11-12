#include<bits/stdc++.h>
using namespace std;
long long ans=0,cnt1,cnt2,cnt3,n;
struct Node{
    int x,y,z,v,id;
}a[100005];
bool cmp(Node p,Node q){
    return p.v<q.v;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        ans=0,cnt1=0,cnt2=0,cnt3=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
            if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
                cnt1++;
                a[i].id=1;
                ans+=a[i].x;
                if(a[i].y>a[i].z){
                    a[i].v=a[i].x-a[i].y;
                }else{
                    a[i].v=a[i].x-a[i].z;
                }
            }else if(a[i].y>=a[i].x&&a[i].y>=a[i].z){
                cnt2++;
                a[i].id=2;
                ans+=a[i].y;
                if(a[i].x>a[i].z){
                    a[i].v=a[i].y-a[i].x;
                }else{
                    a[i].v=a[i].y-a[i].z;
                }
            }else{
                cnt3++;
                a[i].id=3;
                ans+=a[i].z;
                if(a[i].x>a[i].y){
                    a[i].v=a[i].z-a[i].x;
                }else{
                    a[i].v=a[i].z-a[i].y;
                }
            }
        }
        sort(a+1,a+n+1,cmp);
        int t=n/2;
        if(cnt1>t){
            for(int i=1;i<=n,cnt1>t;i++){
                if(a[i].id==1){
                    ans-=a[i].v;
                    cnt1--;
                }
            }
        }else if(cnt2>t){
            for(int i=1;i<=n,cnt2>t;i++){
                if(a[i].id==2){
                    ans-=a[i].v;
                    cnt2--;
                }
            }
        }else if(cnt3>t){
            for(int i=1;i<=n,cnt3>t;i++){
                if(a[i].id==3){
                    ans-=a[i].v;
                    cnt3--;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
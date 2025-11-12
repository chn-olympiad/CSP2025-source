#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int t;
struct node{
    int x,y,z,c,mx;
    bool operator<(const node &x)const{
        return c<x.c;
    }
};
node a[maxn];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        int cnt1,cnt2,cnt3,ans;
        cnt1=cnt2=cnt3=ans=0;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
        }
        for(int i=1;i<=n;i++){
            int mx=max(a[i].x,max(a[i].y,a[i].z));
            if(mx==a[i].x) cnt1++,a[i].c=mx-max(a[i].y,a[i].z),a[i].mx=1;
            else if(mx==a[i].y) cnt2++,a[i].c=mx-max(a[i].z,a[i].x),a[i].mx=2;
            else cnt3++,a[i].c=mx-max(a[i].x,a[i].y),a[i].mx=3;
            ans+=mx;
        }
        sort(a+1,a+n+1);
        if(cnt1>n/2){
            for(int i=1;i<=n;i++){
                if(a[i].mx==1&&cnt1>n/2) ans-=a[i].c,cnt1--;
            }
        }
        else if(cnt2>n/2){
            for(int i=1;i<=n;i++){
                if(a[i].mx==2&&cnt2>n/2) ans-=a[i].c,cnt2--;
            }
        }
        else if(cnt3>n/2){
            for(int i=1;i<=n;i++){
                if(a[i].mx==3&&cnt3>n/2) ans-=a[i].c,cnt3--;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

#include<bits//stdc++.h>
using namespace std;
#define ll long long
struct st{
    ll x,y,z,id;
};
struct st1{
    ll n,id;
};
bool pd(st1 a,st1 b){
    return a.n>b.n;
}
ll m,n,x,y,z,ans;
st s[100500];
st1 a1[100500],a2[100500],a3[100500];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>m;
    while(m--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>s[i].x>>s[i].y>>s[i].z;
            a1[i].n=s[i].x-max(s[i].y,s[i].z);
            a2[i].n=s[i].y-max(s[i].x,s[i].z);
            a3[i].n=s[i].z-max(s[i].x,s[i].y);
            if(s[i].x>=s[i].y&&s[i].x>=s[i].z) x++;
            if(s[i].y>=s[i].x&&s[i].y>=s[i].y) y++;
            if(s[i].z>=s[i].z&&s[i].z>=s[i].x) z++;
            a1[i].id=i;
            a2[i].id=i;
            a3[i].id=i;
        }
        if(x>n/2){
            sort(a1+1,a1+1+n,pd);
            for(int i=n/2+1;i<=n;i++){
                s[a1[i].id].x=-1;
            }
        }
        else if(y>n/2){
            sort(a2+1,a2+1+n,pd);
            for(int i=n/2+1;i<=n;i++){
                s[a2[i].id].y=-1;
            }
        }
        else{
            sort(a3+1,a3+1+n,pd);
            for(int i=n/2+1;i<=n;i++){
                s[a3[i].id].z=-1;
            }
        }
        //cout<<x<<" "<<y<<" "<<z<<'\n';
        for(int i=1;i<=n;i++){
            //cout<<s[i].x<<" "<<s[i].y<<" "<<s[i].z<<'\n';
            ans+=max(max(s[i].x,s[i].y),s[i].z);
        }
        cout<<ans<<'\n';
        ans=0;
        x=0;
        y=0;
        z=0;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
ll t,n,tot,ans,sum[3];
struct node{
    ll a,b,c;
    ll ax,in;
}a[N],b[N];
bool cmp1(node x,node y){
    return x.ax>y.ax;
}bool cmp2(node x,node y){
    return x.in>y.in;
}
void solve(){
    sum[0]=sum[1]=sum[2]=0;
    cin>>n;ans=tot=0;
    for(int i=1;i<=n;i++){
        cin>>a[i].a>>a[i].b>>a[i].c;
        a[i].ax=2*max(a[i].a,max(a[i].b,a[i].c))-(a[i].a+a[i].b+a[i].c-min(a[i].a,min(a[i].b,a[i].c)));
        a[i].in=a[i].a+a[i].b+a[i].c-max(a[i].a,max(a[i].b,a[i].c))-2*min(a[i].a,min(a[i].b,a[i].c));
    }
    sort(a+1,a+1+n,cmp1);
    for(int i=1;i<=n;i++){
        if(a[i].a>=a[i].b&&a[i].a>=a[i].c){
            if(sum[0]==n/2){
                a[i].a=-1;
                b[++tot]=a[i];
                continue;
            }
            ans+=a[i].a;
            sum[0]++;
        }else if(a[i].b>=a[i].a&&a[i].b>=a[i].c){
            if(sum[1]==n/2){
                a[i].b=-1;
                b[++tot]=a[i];
                continue;
            }
            ans+=a[i].b;
            sum[1]++;
        }else if(a[i].c>=a[i].b&&a[i].c>=a[i].a){
            if(sum[2]==n/2){
                a[i].c=-1;
                b[++tot]=a[i];
                continue;
            }
            ans+=a[i].c;
            sum[2]++;
        }
    }
    sort(b+1,b+1+tot,cmp2);
    for(int i=1;i<=tot;i++){
        if(b[i].a==-1){
            if(b[i].b>=b[i].c||sum[2]==n/2)
                ans+=b[i].b;
            else
                ans+=b[i].c;
        }if(b[i].b==-1){
            if(b[i].a>=b[i].c||sum[2]==n/2)
                ans+=b[i].a;
            else
                ans+=b[i].c;
        }if(b[i].c==-1){
            if(b[i].a>=b[i].b||sum[1]==n/2)
                ans+=b[i].a;
            else
                ans+=b[i].b;
        }
    }
    cout<<ans<<'\n';
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
        solve();
    return 0;
}

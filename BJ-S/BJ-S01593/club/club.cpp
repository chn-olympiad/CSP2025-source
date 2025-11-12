#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
ll t,n,mx,ans=0;
bool vis=false;
struct qst{
    ll a;
    ll b;
    ll c;
}a[100010];
bool cmp(qst p,qst q){
    return p.a>q.a;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i].a>>a[i].b>>a[i].c;
            if(a[i].b==0||a[i].c==0){
                vis=true;
            }
            mx=max(a[i].a,a[i].b);
            mx=max(mx,a[i].c);
            ans+=mx;
        }
        if(!vis){
            cout<<ans<<endl;
        }else{
            ll sum=0;
            sort(a+1,a+1+n,cmp);
            for(int i=n;i>=n/2;i--){
                sum+=a[i].a;
            }
            cout<<sum<<endl;
        }
    }
    return 0;
}
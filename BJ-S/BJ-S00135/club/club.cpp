#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int vis[100005];
int c1,c2,c3;
int ans;
struct mem{
    int a,b,c;
    int d;
}a[100005];
bool cmp(mem x,mem y){
    return x.d>y.d;
}
int run(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].a>>a[i].b>>a[i].c;
        a[i].d=2*max(a[i].a,max(a[i].b,a[i].c))-a[i].a-a[i].b-a[i].c+min(a[i].a,min(a[i].b,a[i].c));
    }
    sort(a+1,a+n+1,cmp);
    //for(int i=1;i<=n;i++) cout<<a[i].a<<" "<<a[i].b<<" "<<a[i].c<<endl;
    for(int i=1;i<=n;i++){
        if(a[i].a==max(a[i].a,max(a[i].b,a[i].c))){
            if(c1<n/2){
                ans+=a[i].a;
                c1++;
            }
            else ans+=max(a[i].b,a[i].c);
        }
        else if(a[i].b==max(a[i].a,max(a[i].b,a[i].c))){
            if(c2<n/2){
                ans+=a[i].b;
                c2++;
            }
            else ans+=max(a[i].a,a[i].c);
        }
        else if(a[i].c==max(a[i].a,max(a[i].b,a[i].c))){
            if(c3<n/2){
                ans+=a[i].c;
                c3++;
            }
            else ans+=max(a[i].a,a[i].b);
        }
        //cout<<a[i].a<<' '<<a[i].b<<' '<<a[i].c<<' '<<ans<<' '<<2*max(a[i].a,max(a[i].b,a[i].c))-a[i].a-a[i].b-a[i].c+min(a[i].a,min(a[i].b,a[i].c))<<endl;
    }
    cout<<ans<<endl;
    for(int i=1;i<=n;i++) vis[i]=0;
    return 0;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        c1=c2=c3=0;
        ans=0;
        run();
    }
    return 0;
}

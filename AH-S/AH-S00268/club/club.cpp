#include<bits/stdc++.h>
using namespace std;
long long t,n,ans;
struct stu{
    long long a,b,c;
}d[100010];
bool cmp(const stu &x,const stu &y){
    if(x.a!=y.a)return x.a>y.a;
    if(x.b!=y.b)return x.b>y.b;
    return x.c>y.c;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        ans=0;
        for(long long i=1;i<=n;i++){
            cin>>d[i].a>>d[i].b>>d[i].c;
        }
        sort(d+1,d+n+1,cmp);
        for(long long i=1;i<=n;i++){
        if(i<=n/2)ans+=d[i].a;
            if(i>n/2)ans+=d[i].b;
        }
        cout<<ans<<endl;
    }
    return 0;
}

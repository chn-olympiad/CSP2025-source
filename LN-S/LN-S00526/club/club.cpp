#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,T,ans;
struct stu{
    int a,b,c;
    int x,y;
    bool u;
}a[N];
bool cmp(stu p,stu q){
    if(p.x!=q.x){
        return p.x>q.x;
    }else if(p.x==q.x){
        return p.y>q.y;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].a>>a[i].b>>a[i].c;
            a[i].x=max(a[i].a,max(a[i].b,a[i].c));
            a[i].y=min(max(a[i].a,a[i].b),min(max(a[i].a,a[i].c),max(a[i].b,a[i].c)));
        }
        sort(a+1,a+1+n,cmp);
        for(int i=1;i<=n/2;i++){
            ans+=a[i].x;
        }
        for(int i=n/2;i<=n;i++){
            ans+=a[i].y;
        }
        cout<<ans<<endl;
    }
    return 0;
}

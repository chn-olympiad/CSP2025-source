#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,m,ans,q[100010],l,r;
struct node{
    int num,s;
}a[N],b[N],c[N];
bool cmp(node x,node y){
    return x.s>y.s;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        m=n/2;
        ans=0;
        l=r=0;
        for(int i=1;i<=n;i++){
            cin>>a[i].s>>b[i].s>>c[i].s;
            a[i].num=b[i].num=c[i].num=i;
        }
        if(n==2){
            l=max(a[1].s+b[2].s,a[1].s+c[2].s);
            l=max(l,b[1].s+a[2].s);
            l=max(l,b[1].s+c[2].s);
            l=max(l,c[1].s+a[2].s);
            l=max(l,c[1].s+b[2].s);
            ans=l;
        }
        else if(b[1].s==0&&c[1].s==0){
            sort(a+1,a+n+1,cmp);
            for(int i=1;i<=m;i++) ans+=a[i].s;
        }
        else if(c[1].s==0){
            sort(b+1,b+n+1,cmp);
            sort(a+1,a+n+1,cmp);
            for(int i=1;i<=m;i++){
                ans+=b[i].s+a[i].s;
            }
        }
        else{
            for(int i=1;i<=n;i++) ans+=a[i].s;
        }
        cout<<ans<<endl;
    }
    return 0;
}
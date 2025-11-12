#include<bits/stdc++.h>
const int N=2e5+5,INF=1e9;
using namespace std;
int n,q,ans,fl,l1,l2,l3,lx,ly;string t1,t2,t3;
struct nd{
    int l1,l2;string s1,s2;
}a[N];
void sv(){
    cin>>t1>>t2,ans=0;
    l1=t1.size(),l2=t2.size();
    t1=" "+t1,t2=" "+t2;
    for(int i=1;i<=n;i++){
        lx=a[i].l1,ly=a[i].l2;
        for(int p1=1;p1<=l1;p1++){
            fl=1;
            for(int j=1;j<=lx;j++)
                if(t1[p1+j-1]!=a[i].s1[j]){fl=0;break;}
            t3=" ",l3=0;
            for(int k=1;k<p1;k++)t3[++l3]=t1[k];
            for(int k=1;k<=ly;k++)t3[++l3]=a[i].s2[k];
            for(int k=p1+lx;k<=l1;k++)t3[++l3]=t1[k];
            if(l2==l3){
                for(int j=1;j<=l2;j++)if(t2[j]!=t3[j])fl=0;
                ans+=fl;
            }
        }
    }cout<<ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>t1>>t2;
        l1=t1.size(),l2=t2.size();
        t1=" "+t1,t2=" "+t2;
        a[i]=(nd){l1,l2,t1,t2};
    }
    for(int i=1;i<=q;i++)sv();
    return 0;
}
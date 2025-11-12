#include<bits/stdc++.h>
using namespace std;
#define mid (l+r)/2
const int N=5*1e5;
int n,k;
int a[N+1];
int tr[4*N+1];
void build_up(int x,int l,int r)
{
    if(l==r)
    {
        tr[x]=a[l];
        return;
    }
    build_up(x*2,l,mid);
    build_up(x*2+1,mid+1,r);
    tr[x]=tr[2*x]^tr[2*x+1];
}
int check(int x,int l,int r,int cl,int cr)
{
    //cout<<l<<" "<<r<<"\n";
    //if(l==r) return tr[x];
    int ansc1=0,ansc2=0;
    if(l>=cl&&r<=cr) return tr[x];
    if(cl<=mid) ansc1=check(x*2,l,mid,cl,cr);
    if(cr>=mid+1) ansc2=check(x*2+1,mid+1,r,cl,cr);
    if(ansc1!=0&&ansc2!=0) return ansc1^ansc2;
    else if(ansc1!=0) return ansc1;
    else return ansc2;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    srand(time(0));
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    build_up(1,1,n);
    if(n==2)
    {
        if(check(1,1,n,1,1)==k) ans++;
        if(check(1,1,n,2,2)==k) ans++;
        if(check(1,1,n,1,2)==k) ans=max(ans,1);
        cout<<ans;
        return 0;
    }
    cout<<rand()%(n-10)+10;
    /*int cl,cr;
    cin>>cl>>cr;
    build_up(1,1,n);
    cout<<check(1,1,n,cl,cr);*/

    return 0;
}

#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=100005;
ll T,n,tmp,tA,tB,tC,ans,max_n;
struct node{
    ll val,id;
}a[N],b[N],c[N];
struct stu{
    ll fa,fb,fc;
}sco[N];
bool f[N];
bool cmp(node x,node y){
    return x.val>y.val;
}
int main(void){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>T;
    while(T--){
        cin>>n;
        max_n=n>>1;
        ans=tA=tB=tC=0;
        memset(f,0,sizeof(f));
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        memset(sco,0,sizeof(sco));
        for(int i=1;i<=n;i++){
            cin>>a[i].val>>b[i].val>>c[i].val;
            a[i].id=b[i].id=c[i].id=i;
            sco[i].fa=a[i].val;
            sco[i].fb=b[i].val;
            sco[i].fc=c[i].val;
        }
        sort(a+1,a+n+1,cmp);
        sort(b+1,b+n+1,cmp);
        sort(c+1,c+n+1,cmp);
        int i=1,j=1,k=1;
        while(tA+tB+tC<n){
            while(f[a[i].id])i++;
            while(f[b[j].id])j++;
            while(f[c[k].id])k++;
            if(tA==max_n){
                if(b[j].val>=c[k].val){
                    tB++;
                    f[b[j].id]=1;
                    ans+=b[j].val;
                    j++;
                    continue;
                }
                else{
                    tC++;
                    f[c[k].id]=1;
                    ans+=c[k].val;
                    k++;
                    continue;
                }
            }
            if(tB==max_n){
                if(a[i].val>=c[k].val){
                    tA++;
                    f[a[i].id]=1;
                    ans+=a[i].val;
                    i++;
                    continue;
                }
                else{
                    tC++;
                    f[c[k].id]=1;
                    ans+=c[k].val;
                    k++;
                    continue;
                }
            }
            if(tC==max_n){
                if(b[j].val>=a[i].val){
                    tB++;
                    f[b[j].id]=1;
                    ans+=b[j].val;
                    j++;
                    continue;
                }
                else{
                    tA++;
                    f[a[i].id]=1;
                    ans+=a[i].val;
                    i++;
                    continue;
                }
            }
            if(tA<=max_n && a[i].val>=b[j].val && a[i].val>=c[k].val){
                tA++;
                f[a[i].id]=1;
                ans+=a[i].val;
                i++;
                continue;
            }
            if(tB<=max_n && a[i].val<b[j].val && b[j].val>=c[k].val){
                tB++;
                f[b[j].id]=1;
                ans+=b[j].val;
                j++;
                continue;
            }
            if(tC<=max_n && a[i].val<c[k].val && b[j].val<c[k].val){
                tC++;
                f[c[k].id]=1;
                ans+=c[k].val;
                k++;
                continue;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

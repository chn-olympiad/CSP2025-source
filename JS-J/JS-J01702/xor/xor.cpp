#include<bits/stdc++.h>
using namespace std;
const int N=1.5e6+5;
struct node{
    int l,r;
    bool operator <(const node &A) const{
        if(r!=A.r)  return r<A.r;
        return l<A.l;
    }
}c[N];
int n,k;
int cnt=0,ans=0,cut=0;
int a[N],s[N],lst[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    memset(lst,-1,sizeof(lst));
    lst[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]^a[i];
        int aim=s[i]^k;
        if(lst[aim]==-1){
            lst[s[i]]=i;
            continue;
        }
        int pos=lst[aim]+1;
        c[++cnt]={pos,i};
        lst[s[i]]=i;
    }
    sort(c+1,c+cnt+1);
    for(int i=1;i<=cnt;i++){
        if(c[i].l<=cut)  continue;
        ans++;
        cut=c[i].r;
    }
    cout<<ans;
    return 0;
}

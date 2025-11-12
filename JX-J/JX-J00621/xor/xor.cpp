#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=50005;
struct fr{
    int l, r;
}t[N];
bool cmp(fr a,fr b){
    if(a.l!=b.l)return a.l<b.l;
    return a.r<b.r;
}
int a[N],s[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,cnt=0;
    cin>>n>>k;
    for(int i=1;i<=n;++i)cin>>a[i];
    s[1]=a[1];
    for(int i=2;i<=n;++i)s[i]=s[i-1]^a[i];
    for(int i=1;i<=n;++i){
        for(int j=i;j<=n;++j){
            if((s[j]^s[i-1])==k){
                t[++cnt].l=i;
                t[cnt].r=j;
            }
        }
    }
    sort(t+1,t+cnt+1,cmp);
    //for(int i=1;i<=cnt;++i){
    //    cout<<t[i].l<<" "<<t[i].r<<endl;
    //}
    int nl=t[cnt].l,nr=t[cnt].r,num=1;

    for(int i=cnt-1;i>=1;--i){
        if(t[i].r<nl){
            ++num;
            nl=t[i].l;
        }
    }
    cout<<num;
    return 0;
}

#include<iostream>
#include<cstdio>
using namespace std;
int n,k,a[500005],q[25][500005],c[500005],ans=0;
void init(){
    for(int j=0;j<=20;j++)
        for(int i=1;i<=n;i++)
            q[j][i]=q[j][i-1]+((a[i]&(1<<j)&&1));
    return;
}
inline bool check(int l,int r){
    for(int j=0;j<=20;j++)
        if(((q[j][r]-q[j][l-1])&1)!=((k&(1<<j))&&1))return false;
    return true;
}
inline int lowbit(int x){return x&-x;}
void add(int x){
    for(;x<=n;x+=lowbit(x))c[x]++;
    return;
}
int get(int x){
    int sum=0;
    for(;x;x-=lowbit(x))sum+=c[x];
    return sum;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    init();
    for(int len=1;len<=n;len++){
        for(int l=1;l<=n-len+1;l++){
            int r=l+len-1;
            if(get(r)-get(l-1)==0&&check(l,r)){
                for(int i=l;i<=r;i++)add(i);
                ans++;
            }
        }
    }
    for(int len=1;len<=n;len++){
        for(int l=1;l<=n-len+1;l++){
            int r=l+len-1;
            if(get(r)-get(l-1)==0&&check(l,r)){
                for(int i=l;i<=r;i++)add(i);
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}

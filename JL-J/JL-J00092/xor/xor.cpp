#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
struct node{int x,y;}c[2*N];
int n,k,l=-1,now=0,ans=0,a[N];
bool cmp(node xx,node yy){
    if(xx.y!=yy.y)return xx.y<yy.y;
    return xx.x>yy.x;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n>1e3){
        for(int i=1;i<=n;i++)if(a[i]==k)ans++;
        for(int i=1;i<=n;i++)if(a[i]^a[i+1]==k)ans++,i++;
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=n;i++){int sum=a[i];if(sum==k){now++,c[now]={i,i};}for(int j=i+1;j<=n;j++){sum=sum^a[j];if(sum==k){now++,c[now]={i,j};j=n+1;}}}
    sort(c+1,c+1+now,cmp);
    for(int i=1;i<=now;i++)if(c[i].x>l)ans++,l=c[i].y;
    cout<<ans;
    return 0;
}

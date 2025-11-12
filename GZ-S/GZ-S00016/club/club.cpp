//GZ-S00016 中央民族大学附属中学贵阳学校 伍兴睿麟
#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int t,n,a[100005][3],k[3],h[100005],y,mx[100005],len,p[100005];
ll ans;
void so(){
    cin>>n;
    ans=0;
    y=-1;
    len=k[0]=k[1]=k[2]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i][0]>>a[i][1]>>a[i][2];
        ll z=max(max(a[i][0],a[i][1]),a[i][2]);
        if(z==a[i][0]) ans+=a[i][0],h[i]=0,mx[i]=max(a[i][1],a[i][2]),k[0]++;
        else if(z==a[i][1]) ans+=a[i][1],h[i]=1,mx[i]=max(a[i][0],a[i][2]),k[1]++;
        else ans+=a[i][2],h[i]=2,mx[i]=max(a[i][1],a[i][0]),k[2]++;
    }
    if(k[0]>n/2) y=0;
    else if(k[1]>n/2) y=1;
    else if(k[2]>n/2) y=2;
    for(int i=1;i<=n;i++){
        if(h[i]==y){
            p[++len]=a[i][h[i]]-mx[i];
        }
    }
    sort(p+1,p+1+len);
    for(int i=1;k[y]>n/2;k[y]--,i++) ans-=p[i];
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        so();
    }
    return 0;
}

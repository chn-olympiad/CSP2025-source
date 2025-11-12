#include<bits/stdc++.h>
using namespace std;
int n,a[100010][3],f[100010],tot,t[100010],s[3];
void solve(){
    cin>>n;tot=0;
    s[0]=s[1]=s[2]=0;
    long long sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i][0]>>a[i][1]>>a[i][2];
        if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2])
            s[0]++,
            sum+=a[i][0],
            f[i]=0;
        else if(a[i][1]>=a[i][2])
            s[1]++,
            sum+=a[i][1],
            f[i]=1;
        else
            s[2]++,
            sum+=a[i][2],
            f[i]=2;
    }
    int p=-1,x,y;
    if(s[0]>n/2)p=0,x=1,y=2;
    if(s[1]>n/2)p=1,x=0,y=2;
    if(s[2]>n/2)p=2,x=0,y=1;
    if(p==-1){
        cout<<sum<<'\n';
        return;
    }
    for(int i=1;i<=n;i++)
        if(f[i]==p)
            t[++tot]=min(a[i][p]-a[i][x],a[i][p]-a[i][y]);
    sort(t+1,t+tot+1);
    for(int w=1;w<=s[p]-(n/2);w++)
        sum-=t[w];
    cout<<sum<<'\n';
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T;for(cin>>T;T;T--)solve();
    return 0;
}
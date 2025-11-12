#include<bits/stdc++.h>
using namespace std;
typedef long long i64;
const int N=1e5+5;
int n,a[N][3],c[N],t[N],tot[3];
vector<int>cg;
void solve(){
    cin>>n;i64 ans=0;tot[0]=tot[1]=tot[2]=0;
    for(int i=1;i<=n;i++)cin>>a[i][0]>>a[i][1]>>a[i][2];
    for(int i=1;i<=n;i++){
        int mx=0;
        for(int j=0;j<=2;j++)if(a[i][mx]<a[i][j])mx=j;
        c[i]=mx;tot[mx]++;ans+=a[i][mx];
    }int id=-1;
    if(tot[0]>n/2)id=0;
    else if(tot[1]>n/2)id=1;
    else if(tot[2]>n/2)id=2;
    for(int i=1;i<=n;i++)
        if(c[i]==id)cg.push_back(i),t[i]=a[i][id]-max(a[i][(id+1)%3],a[i][(id+2)%3]);
    sort(cg.begin(),cg.end(),[](int x,int y){
        return t[x]<t[y];
    });
    if(id>=0){
        int sz=tot[id]-n/2;
        for(int i=0;i<sz;i++)ans-=t[cg[i]];
    }
    cout<<ans<<'\n';cg.clear();
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;while(_--)solve();
}
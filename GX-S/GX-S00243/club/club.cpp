#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int tt,n,tot[4],b[N+5],c[N+5];
pair<int,int> a[4];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>tt;
    for(int o=1;o<=tt;o++){
        cin>>n; int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++) cin>>a[j].first,a[j].second=j;
            sort(a+1,a+4);
            tot[a[3].second]++,ans+=a[3].first;
            b[i]=a[3].first-a[2].first,c[i]=a[3].second;
        }
        int cod=0,mx=0;
        for(int i=1;i<=3;i++){
            if(tot[i]>=mx) mx=tot[i],cod=i;
        }
        for(int i=1;i<=n;i++){
            if(c[i]!=cod) b[i]=1e9;
        }
        sort(tot+1,tot+4);
        sort(b+1,b+n+1);
        for(int i=1;i<=tot[3]-n/2;i++) ans-=b[i];
        cout<<ans<<"\n";
        for(int i=1;i<=3;i++) tot[i]=0;
    }
    return 0;
}
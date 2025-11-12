#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
int a[N];
bool cmp(int a,int b){
    return a>b;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        memset(a,0,sizeof(a));
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            int a1,b,c;
            cin>>a1>>b>>c;
            int m=max({a1,b,c});
            a[i]=m;
        }
        sort(a+1,a+n+1,cmp);
        int ans=0,k=n/2;
        for(int i=1;i<=k;i++)ans+=a[i];
        cout<<ans<<"\n";
    }
    
    return 0;
}

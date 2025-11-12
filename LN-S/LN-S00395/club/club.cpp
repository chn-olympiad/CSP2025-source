#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        long long ans=0;
        long long cnt[3];
        long long a[n+1],b[n+1],c[n+1];
        a[0]=0;
        b[0]=0;
        c[0]=0;
        bool tmp=true,tmp2=true;
        for(long long i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            if((b[i]!=c[i])||(b[i]!=0))tmp=false;
            if(c[i]!=0) tmp2=false;
        }
        if(tmp==true){
            sort(a+1,a+n+1);
            for(long long i=n;i>=n/2+1;i--){
                ans+=a[i];
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}

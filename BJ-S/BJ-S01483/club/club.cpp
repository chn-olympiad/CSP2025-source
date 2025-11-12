#include<bits/stdc++.h>
using namespace std;
int t,n,a1,b1,c1,maxx=0,f=0;
long long ans=0;
int a[100005];
int b[100005];
int c[100005];
int ah[100005];
int bh[100005];
int ch[100005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        a1=0;
        b1=0;
        c1=0;
        ans=0;
        maxx=0;
        f=0;
        for(int i=1;i<=n;i++){
            ah[i]=20005;
            bh[i]=20005;
            ch[i]=20005;
        }
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            maxx=max(a[i],b[i]);
            maxx=max(maxx,c[i]);
            ans+=maxx;
            if(maxx==a[i]){
                a1++;
                ah[i]=min(a[i]-b[i],a[i]-c[i]);
            }
            else if(maxx==b[i]){
                b1++;
                bh[i]=min(b[i]-a[i],b[i]-c[i]);
            }
            else{
                c1++;
                ch[i]=min(c[i]-a[i],c[i]-b[i]);
            }
        }
        if(a1<=n/2 && b1<=n/2 && c1<=n/2){
            cout<<ans<<endl;
            continue;
        }
        sort(ah+1,ah+n+1);
        sort(bh+1,bh+n+1);
        sort(ch+1,ch+n+1);
        if(a1>n/2){
            f=a1-n/2;
            for(int i=1;i<=f;i++){
                ans-=ah[i];
            }
            cout<<ans<<endl;
            continue;
        }
        else if(b1>n/2){
            f=b1-n/2;
            for(int i=1;i<=f;i++){
                ans-=bh[i];
            }
            cout<<ans<<endl;
            continue;
        }
        else{
            f=c1-n/2;
            for(int i=1;i<=f;i++){
                ans-=ch[i];
            }
            cout<<ans<<endl;
            continue;
        }
    }
    return 0;
}

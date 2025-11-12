#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long a[N][10];
long long a1[N],a2[N],a3[N],c[N];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int cnt1=0,cnt2=0,cnt3=0,cnt4=0;
        memset(a1,0,sizeof(a1));
        memset(a2,0,sizeof(a2));
        memset(a3,0,sizeof(a3));
        memset(c,0,sizeof(c));
        long long maxn=0,ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            maxn=max(a[i][1],(max(a[i][2],a[i][3])));
            if(a[i][1]==maxn){
                ans+=a[i][1];
                a1[++cnt1]=a[i][1];
                continue;
            }
            if(a[i][2]==maxn){
                ans+=a[i][2];
                a2[++cnt2]=a[i][2];
                continue;
            }
            if(a[i][3]==maxn){
                ans+=a[i][3];
                a3[++cnt3]=a[i][3];
                continue;
            }
        }
        if(cnt1>=cnt2&&cnt1>=cnt3){
            if(cnt1<=n/2){
                cout<<ans<<endl;
                continue;
            }
            for(int i=1;i<=n;i++){
                maxn=max(a[i][1],(max(a[i][2],a[i][3])));
                if(a[i][1]==maxn){
                    c[++cnt4]=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
                }
            }
            sort(c+1,c+1+cnt1);
            for(int i=1;i<=cnt1-n/2;i++){
                ans-=c[i];
            }
            cout<<ans<<endl;
            continue;
        }
        if(cnt2>=cnt1&&cnt2>=cnt3){
            if(cnt2<=n/2){
                cout<<ans<<endl;
                continue;
            }
            for(int i=1;i<=n;i++){
                maxn=max(a[i][1],(max(a[i][2],a[i][3])));
                if(a[i][2]==maxn){
                    c[++cnt4]=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
                }
            }
            sort(c+1,c+1+cnt2);
            for(int i=1;i<=cnt2-n/2;i++){
                ans-=c[i];
            }
            cout<<ans<<endl;
            continue;
        }
        if(cnt3>=cnt2&&cnt3>=cnt1){
            if(cnt3<=n/2){
                cout<<ans<<endl;
                continue;
            }
            for(int i=1;i<=n;i++){
                maxn=max(a[i][1],(max(a[i][2],a[i][3])));
                if(a[i][3]==maxn){
                    c[++cnt4]=min(a[i][3]-a[i][2],a[i][3]-a[i][1]);
                }
            }
            sort(c+1,c+1+cnt3);
            for(int i=1;i<=cnt3-n/2;i++){
                ans-=c[i];
            }
            cout<<ans<<endl;
            continue;
        }
    }
    return 0;
}


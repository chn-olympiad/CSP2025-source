#include<bits/stdc++.h>
#define piii pair<int,pair<int,int>>
using namespace std;
const int maxn=1e5+10;
int n,T,ans=0;
piii a[maxn];
bool cmp(piii x, piii y){
    if(x.first!=y.first) return x.first>y.first;
    if(x.second.first!=y.second.first) return x.second.first<y.second.first;
    return x.second.second<y.second.second;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> T;
    while(T--){
        bool all2=true;
        bool all3=true;
        cin >> n;
        ans=0;
        for(int i=1;i<=n;i++){
            cin >> a[i].first >> a[i].second.first >> a[i].second.second;
            if(a[i].second.first!=0) all2=false;
            if(a[i].second.second!=0) all3=false;
        }
        if(n==2){
            int a0=a[1].first;
            int b0=a[1].second.first;
            int c0=a[1].second.second;
            int a1=a[2].first;
            int b1=a[2].second.first;
            int c1=a[2].second.second;
            cout << max(a0+b1,max(a0+c1,max(b0+a1,max(b0+c1,max(c0+a1,c0+b1))))) << endl;
            continue;
        }
        if(n<=17){
            long long ans=0;
            for(long long i=0;i<pow(3,n+1);i++){
                long long ti=i,idx=1,tmp=0,c1=0,c2=0,c3=0;
                while(idx<=n){
                    if(ti%3==0){
                        tmp+=a[idx].first;
                        c1++;
                    }
                    if(ti%3==1){
                        tmp+=a[idx].second.first;
                        c2++;
                    }
                    if(ti%3==2){
                        tmp+=a[idx].second.second;
                        c3++;
                    }
                    ti/=3;
                    idx++;
                }
                if(c1<=n/2 && c2<=n/2 && c3<=n/2 && c1+c2+c3==n){
                    ans=max(ans,tmp);
                }
            }
            cout << ans << endl;
            continue;
        }
        if(all2 && all3){
            sort(a+1,a+n+1,greater<piii>());
            long long ans=0;
            for(int i=1;i<=n/2;i++){
                ans+=a[i].first;
            }
            cout << ans << endl;
            continue;
        }
        if(all2 || all3){
            long long diff[maxn]={0};
            for(int i=1;i<=n;i++){
                ans+=a[i].first;
                diff[i]=a[i].second.first-a[i].first;
            }
            sort(diff+1,diff+n+1);
            for(int i=n/2+1;i<=n;i++){
                ans+=diff[i];
            }
            cout << ans << endl;
            continue;
        }
    }
    return 0;
}
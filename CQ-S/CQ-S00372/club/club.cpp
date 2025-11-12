#include<iostream>
#include<queue>
#include<utility>
#include<algorithm>
constexpr int maxn=1e5+5;
int t,n,a[maxn],b[maxn],c[maxn],k[maxn];
std::priority_queue<int>l;
int main(){
    std::freopen("club.in","r",stdin);
    std::freopen("club.out","w",stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin>>t;
    while(t--){
        while(!l.empty()) l.pop();
        std::cin>>n;
        for(int i=1;i<=n;++i) std::cin>>a[i]>>b[i]>>c[i];
        int cnt1=0,cnt2=0,cnt3=0,ans=0;
        for(int i=1;i<=n;++i){
            if(a[i]>=b[i]&&a[i]>=c[i]) k[i]=1,++cnt1,ans+=a[i];
            else if(b[i]>=a[i]&&b[i]>=c[i]) k[i]=2,++cnt2,ans+=b[i];
            else k[i]=3,++cnt3,ans+=c[i];
        }
        int s=0;
        if(cnt1>n/2){s=cnt1-n/2;for(int i=1;i<=n;++i) if(k[i]==1) l.push(std::max(b[i],c[i])-a[i]);}
        else if(cnt2>n/2){s=cnt2-n/2;for(int i=1;i<=n;++i) if(k[i]==2) l.push(std::max(a[i],c[i])-b[i]);}
        else if(cnt3>n/2){s=cnt3-n/2;for(int i=1;i<=n;++i) if(k[i]==3) l.push(std::max(a[i],b[i])-c[i]);}
        else{std::cout<<ans<<'\n';continue;}
        while(s--){ans+=l.top();l.pop();}
        std::cout<<ans<<'\n';
    }
    return 0;
}
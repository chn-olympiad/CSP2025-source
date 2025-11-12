#include <bits/stdc++.h>
using namespace std;
int a[100005][4];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        vector<int> f,w,r;
        int n;
        cin>>n;
        int ans=0;
        int maxx=0;
        for(int i=1;i<=n;i++){
            int b,c,d;
            cin>>b>>c>>d;
            maxx=max({b,c,d});
            if(maxx==b){
                ans+=b;
                f.push_back(b);
            }
            else if(maxx==c){
                ans+=c;
                w.push_back(c);
            }
            else if(maxx==d){
                ans+=d;
                r.push_back(d);
            }
        }
        sort(f.begin(),f.end());
        sort(w.begin(),w.end());
        sort(r.begin(),r.end());
        if(f.size()>n/2){
            for(int i=0;i<=f.size()-n/2-1;i++){
                ans-=f[i];
            }
        }
        if(w.size()>n/2){
            for(int i=0;i<=w.size()-n/2-1;i++){
                ans-=w[i];
            }
        }
        if(r.size()>n/2){
            for(int i=0;i<=r.size()-n/2-1;i++){
                ans-=r[i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

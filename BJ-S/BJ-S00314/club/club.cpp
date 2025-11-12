#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int t,n,ans,cnta,cntb,cntc,a[maxn],b[maxn],c[maxn];
struct Node{
    int sun;
    bool operator<(const Node other)const{
        return sun<other.sun;
    }
};
vector<Node> aa,bb,cc;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while (t--){
        cin>>n;
        ans=cnta=cntb=cntc=0;
        aa.clear();bb.clear();cc.clear();
        for (int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            int tmpmx=max(a[i],max(b[i],c[i]));ans+=tmpmx;
            int z=a[i]+b[i]+c[i]-tmpmx-min(a[i],min(b[i],c[i]));
            if (tmpmx==a[i]){
                cnta++;
                aa.push_back({a[i]-z});
            }
            else if (tmpmx==b[i]){
                cntb++;
                bb.push_back({b[i]-z});
            }
            else {
                cntc++;
                cc.push_back({c[i]-z});
            }
        }
        int tmpans=0;
        if (int(aa.size())>n/2){
            sort(aa.begin(),aa.end());
            for (int i=0;i<int(aa.size())-n/2;i++)
                tmpans+=aa[i].sun;
        }
        else if (int(bb.size())>n/2){
            sort(bb.begin(),bb.end());
            for (int i=0;i<int(bb.size())-n/2;i++)
                tmpans+=bb[i].sun;
        }
        else {
            sort(cc.begin(),cc.end());
            for (int i=0;i<int(cc.size())-n/2;i++)
                tmpans+=cc[i].sun;
        }
        cout << ans-tmpans << '\n';
    }
    return 0;
}

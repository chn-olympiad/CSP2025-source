#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int f[500005];
struct node{int a,b;};
vector<node> v;
bool cmp(node x,node y){
    return x.a<y.a;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    if (k==1 || k==0) {
        int cnt=0;
        for (int i=1;i<=n;i++){
            int a;cin>>a;
            if (a==k) {ans+=cnt/2+1;cnt=0;}
            else cnt++;
        }
        ans+=cnt/2;
        cout<<ans;
        return 0;
    }
    for (int i=1;i<=n;i++) {
        int a;cin>>a;
        f[i]=f[i-1]^a;
    }
    int l=0;
    for (int i=1;i<=n;i++){
        if ((f[i]^f[i-1])==k) {l=i;ans++;}
        else
            for (int j=i-1;j>=l;j--)
                if ((f[i]^f[j])==k){
                    v.push_back({j+1,i});
                    break;
                }
    }
    sort(v.begin(),v.end(),cmp);
    for (int i=0;i<int(v.size());i++){
        int cnt=0;
        for (int j=i+1;j<=n;j++){
            if (v[j].a<=v[i].b) cnt++;
            if (cnt>1) break;
        }
        if (cnt==0) ans++;
        else if (cnt==1) {ans++;i++;}
    }
    cout<<ans;
    return 0;
}

// T1 100p
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
int a[N][3];
vector<int> vec[3];
void slv(){
    cin>>n;
    for(int i=0;i<=2;i++) vec[i].clear();
    int ans=0;
    for(int i=1;i<=n;i++){
        int mx=0,id=0;
        for(int j=0;j<=2;j++){
            cin>>a[i][j];
            if(a[i][j]>mx) mx=a[i][j],id=j;
        }ans+=mx;
        vec[id].push_back(max(a[i][(id+1)%3],a[i][(id+2)%3])-a[i][id]);
    }
    for(int i=0;i<=2;i++){
        sort(vec[i].begin(),vec[i].end());
        while(vec[i].size()>n/2){
            ans+=vec[i].back();
            vec[i].pop_back();
        }
    }cout<<ans<<endl;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;cin>>t;
    while(t--) slv();
    return 0;
}
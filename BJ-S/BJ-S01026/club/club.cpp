#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb emplace_back
#define pii pair<int,int>
#define fi first
#define se second
#define mid (l+r)/2
const int N=1e5+5;
int n,cnt[4];
pii a[N][4];
vector<int>v[4];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T;cin>>T;
    while(T--){
        cin>>n;
        ll sum=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j].fi;
                a[i][j].se=j;
            }
            sort(a[i]+1,a[i]+4);
            cnt[a[i][3].se]++;
            sum+=a[i][3].fi;
            v[a[i][3].se].pb(a[i][3].fi-a[i][2].fi);
        }
        bool flag=1;
        for(int i=1;i<=3;i++){
            sort(v[i].begin(),v[i].end());
            if(cnt[i]>(n/2)){
                flag=0;
                for(int j=0;j<cnt[i]-n/2;j++){
                    sum-=v[i][j];
                }
                cout<<sum<<'\n';
            }
            v[i].clear();
            cnt[i]=0;
        }
        if(flag){
            cout<<sum<<'\n';
        }
    }
    return 0;
}
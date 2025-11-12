#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define SIZE 100001
#define endl '\n'

ll T,n,lim,res;
ll a[SIZE][3];
ll co[SIZE];
ll cnt[3];
vector<ll> vec;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    cin>>T;
    while(T--){    
        cin>>n;
        lim=n/2,res=0;
        memset(cnt,0,sizeof(cnt));
        for(ll i=1;i<=n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            ll x=0;
            if(a[i][1]>a[i][x]) x=1;
            if(a[i][2]>a[i][x]) x=2;
            cnt[x]++;
            co[i]=x;
            res+=a[i][x];
        }
        ll x=-1;
        if(cnt[0]>lim) x=0;
        if(cnt[1]>lim) x=1;
        if(cnt[2]>lim) x=2;

        if(x==-1){
            cout<<res<<endl;
            continue;
        }
        ll y=(x+1)%3;
        ll z=(x+2)%3;
        for(ll i=1;i<=n;i++)
        if(co[i]==x)
        vec.push_back(max(a[i][y],a[i][z])-a[i][x]);
            
        lim=cnt[x]-lim;
        sort(vec.begin(),vec.end());
        while(lim--){
            res+=vec.back();
            vec.pop_back();
        }
        vec.clear();
        cout<<res<<endl;
    }
    return 0;
}
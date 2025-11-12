#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
struct node{
    int a[3],chosen;
    inline int operator[](int x)const{return a[x];}
    inline int& operator[](int x){return a[x];}
}a[100005];

static inline void solve(){
    cin>>n;
    int cnt[]{0,0,0};
    int ans=0;
    for(int i=1;i<=n;++i){
        cin>>a[i][0]>>a[i][1]>>a[i][2];
        if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
            a[i].chosen=0;
            ++cnt[0];
        }else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
            a[i].chosen=1;
            ++cnt[1];
        }else{
            a[i].chosen=2;
            ++cnt[2];
        }
        ans+=max(max(a[i][0],a[i][1]),a[i][2]);
    }
    int over=-1;
    if(2*cnt[0]>n)
        over=0;
    else if(2*cnt[1]>n)
        over=1;
    else if(2*cnt[2]>n)
        over=2;
    if(over==-1){
        cout<<ans<<endl;
        return;
    }
    vector<int>vec;
    for(int i=1;i<=n;++i)
        if(a[i].chosen==over)
            vec.push_back(a[i][over]-max(a[i][(over+1)%3],a[i][(over+2)%3]));
    sort(vec.begin(),vec.end());
    for(int i=0;i<(int)vec.size()-n/2;++i)
        ans-=vec[i];
    cout<<ans<<endl;
}

signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}
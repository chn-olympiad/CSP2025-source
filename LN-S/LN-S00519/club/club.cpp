#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=100005;
int n,a[N],b[N],c[N];

void solve(){
    cin>>n;
    int cnt1=0,cnt2=0,cnt3=0,ans=0;
    vector<int>vec[3];
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
        if(a[i]>=b[i]&&a[i]>=c[i]){
            cnt1++;
            ans+=a[i];
            vec[0].push_back(i);
        }else if(b[i]>=a[i]&&b[i]>=c[i]){
            cnt2++;
            ans+=b[i];
            vec[1].push_back(i);
        }else{
            cnt3++;
            ans+=c[i];
            vec[2].push_back(i);
        }
    }
    if(cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2){
        cout<<ans<<'\n';
        return;
    }
    if(cnt2>n/2){
        swap(cnt1,cnt2),swap(vec[0],vec[1]);
        for(int i=1;i<=n;i++)
            swap(a[i],b[i]);
    }
    if(cnt3>n/2){
        swap(cnt1,cnt3),swap(vec[0],vec[2]);
        for(int i=1;i<=n;i++)
            swap(a[i],c[i]);
    }
    priority_queue< int,vector<int>,greater<int> >q;
    for(int i:vec[0])
        q.push(a[i]-max(b[i],c[i]));
    while((int)q.size()>(n/2)){
        ans-=q.top();
        q.pop();
    }
    cout<<ans<<'\n';
}

signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--)solve();
}

//bai
#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
void fileopen(string s){
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}
int a[500003],s[500003],n,K;
namespace sub12{
    bool check(){return n<=1000;}
    void solve(){
        int i,j,ans=0;
        vector<pair<int,int> > v;
        for(i=1;i<=n;i++){
            for(j=i;j<=n;j++){
                if((s[j]^s[i-1])==K){
                    v.push_back({i,j});
                    break;
                }
            }
        }
        sort(v.begin(),v.end(),[](pair<int,int> a,pair<int,int> b){return a.S<b.S;});
        int lst=0;
        for(auto p:v){
            if(p.F<=lst)continue;
            ans++,lst=p.S;
        }
        cout<<ans;
    }
}
namespace sub13{
    bool check(){
        int i;
        for(i=1;i<=n;i++)if(a[i]>1)return false;
        return true;
    }
    void solve(){
        int i,ans=0;
        if(K==1){
            for(i=1;i<=n;i++)ans+=a[i];
            cout<<ans;
            return;
        }
        int ct=0;
        for(i=1;i<=n;i++){
            if(a[i]==1){
                ct++;
                if(ct==2)ct=0,ans++;
            }
            else{
                ans++,ct=0;
            }
        }
        cout<<ans;
    }
}
signed main(){
    fileopen("xor");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int i;
    cin>>n>>K;
    //cerr<<"n="<<n<<" k="<<K<<'\n';
    for(i=1;i<=n;i++)cin>>a[i],s[i]=s[i-1]^a[i];
    if(sub13::check()){
        sub13::solve();
        exit(0);
    }
    if(sub12::check()){
        sub12::solve();
        exit(0);
    }
    return 0;
}
//@He
/*
9:17 这tm是J组T3？？？
10:04 推不出正解是不是废了
10:16 打了一个60分，但是过了全部大样例（要是欧欧镑数据能这么水就好了（））
11:28 写了一个诡异的O(nk)做法，甲烷了！
11:44 会了特殊性质B，成功多得5pts（）
*/

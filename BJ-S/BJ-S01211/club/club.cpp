#include<bits/stdc++.h>
using namespace std;

const int N=100009;
struct Club{
    int a,b,c,i;

    inline int minn() { return min(this->a, min(this->b, this->c)); }
    inline int maxn() { return max(this->a, max(this->b, this->c)); }
    inline int secondn() {
        int maxn=this->maxn();
        if(maxn==this->a) maxn=max(this->b, this->c);
        else if(maxn==this->b) maxn=max(this->a, this->c);
        else if(maxn==this->c) maxn=max(this->b, this->a);
        return maxn;
    }
    inline int get(int i) { return i==0?a:(i==1?b:c); }

    inline bool operator<(Club &other){
        return this->maxn()>other.maxn();
    }
    inline static bool cmp2(Club &a, Club &other){
        return a.secondn()>other.secondn();
    }
} a[N];

int n;

int solve123[N],solve123cnt[3],solve123ans=0;
void dfs(int t){
    if(t>n){
        int sum=0;
        for(int i=1;i<=n;i++){
            sum+=a[i].get(solve123[i]);
        }
//        if(sum==11){
//            for(int i=1;i<=n;i++) cout<<solve123[i]<<",";
//            cout<<": "<<sum<<endl;
//        }
        solve123ans=max(solve123ans, sum);
    }
    for(int i=0;i<=2;i++){
        if(solve123cnt[i]>=n/2){
            continue;
        }
        ++solve123cnt[i];
        solve123[t]=i;
        dfs(t+1);
        --solve123cnt[i];
    }
}

inline void solve(){
    cin>>n;
    int ans1=0;
    for(int i=1;i<=n;i++){
        cin>>a[i].a>>a[i].b>>a[i].c;
        int minn=a[i].minn();
        a[i].a-=minn;
        a[i].b-=minn;
        a[i].c-=minn;
        a[i].i=i;
        ans1+=minn;
    }
    if(n<=10){
        solve123ans=0;
        memset(solve123cnt, 0, sizeof solve123cnt);
        dfs(1);
        cout<<solve123ans+ans1<<endl;
        return;
    }
    sort(a+1,a+n+1);
    int res[3]={0};
    bool used[N]={0};
    for(int i=1;i<=n;i++){
        int maxn=a[i].maxn();
        for(int k=0;k<=2;k++){
            if(maxn==a[i].get(k)){
                if(res[k]<n/2){
                    ++res[k];
                    ans1+=a[i].get(k);
                    used[a[i].i]=true;
                    //cout<<"USE: i="<<i<<", k="<<k<<endl;
                }
                break;
            }
        }
    }
    sort(a+1,a+n+1,Club::cmp2);
    for(int i=1;i<=n;i++){
        if(used[a[i].i]) continue;
        int maxn=a[i].secondn();
        for(int k=0;k<=2;k++){
            if(maxn==a[i].get(k)){
                if(res[k]<n/2){
                    ++res[k];
                    ans1+=a[i].get(k);
                    //cout<<"USE: i="<<i<<", k="<<k<<endl;
                    break;
                }
            }
        }
    }
    cout<<ans1<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int T;
    cin>>T;
    while(T--){
        solve();
    }

    return 0;
}

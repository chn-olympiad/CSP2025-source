#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N=1e5+10;
int t[10],st[N];
int a[N][10];
int T,n;
long long ans=-1;

bool cmp(int x,int y){
    return x>y;
}
void dfs(int step){
    if(step>n){
        long long sum=0;
        for(int i=1;i<=n;i++){
            sum+=a[i][st[i]];
            t[st[i]]++;
        }
        int f=1;
        for(int i=1;i<=3;i++){
            if(t[i]>n/2){
                f=0;
                break;
            }
        }
        if(f)ans=max(ans,sum);
        memset(t,0,sizeof(t));
        return;
    }
    st[step]=1;
    dfs(step+1);

    st[step]=2;
    dfs(step+1);

    st[step]=3;
    dfs(step+1);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        ans=-1;
        memset(t,0,sizeof(t));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++)cin>>a[i][j];
        }
        if(n<=10){
            dfs(1);
            cout<<ans<<endl;
            continue;
        }
        int fa=1;
        for(int i=1;i<=n;i++){
            if(a[i][2]!=0||a[i][3]!=0){
                fa=0;
                break;
            }
        }
        if(fa){
            long long sum=0;
            vector<int> t;
            for(int i=1;i<=n;i++)t.push_back(a[i][1]);
            sort(t.begin(),t.end(),cmp);
            for(int i=1;i<=n/2;i++)sum+=t[i-1];
            cout<<sum<<endl;
            continue;
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int MAXN=507,MOD=998244353;
string s;
int a[MAXN],sum[MAXN];
int n,m;
bool visited[MAXN];
long long ans;
vector <int>p;
//long long aaa;
void dfs(int cnt){
    if(cnt==n){
        //aaa++;
        //cout<<"aaa"<<endl;
        int can=0;
        for(int i=1;i<=cnt;i++){
            //cout<<p[i]<<" ";
            if(a[p[i]]>sum[i-1]&&s[i]=='1'){
                can++;
            }
        }
        //cout<<endl;
        //cout<<can<<endl;
        if(can>=m){
            ans=(ans+1)%MOD;
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            visited[i]=1;
            p.push_back(i);
            //aaa++;
            dfs(cnt+1);
            p.pop_back();
            visited[i]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    s.insert(0," ");
    //cout<<s;
    p.push_back(0);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1];
        if(s[i]=='0'){
            sum[i]++;
        }
        //cout<<sum[i]<<endl;
    }
    if(sum[n]>n-m){
        cout<<0;
        return 0;
    }
    dfs(0);
    cout<<ans;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=1e5+114;
int n,m,c[N],p[N];
bool used[N];
string s;
int dfs(int pos){
    if(pos>n){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(cnt>=c[p[i]]||s[i-1]=='0') cnt++;
            if(cnt>n-m) return 0;
        }
        return 1;
    }
    int res=0;
    for(int i=1;i<=n;i++){
        if(!used[i]){
            used[i]=1;
            p[pos]=i;
            res+=dfs(pos+1);
            used[i]=0;
        }
    }
    return res;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++) cin>>c[i];
    cout<<dfs(1);
    return 0;
}

//20
#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[5010],b[5010];
bool f[5010];
map<string,int> m;
void check(int k){
    string s;
    for(int i=1;i<=k;i++){
        s=s+to_string(b[i]);
    }
    sort(s.begin(),s.end());
    if(m[s]>1) return;
    m[s]++;
    int ma=INT_MIN,sum=0;
    for(int i=1;i<=k;i++){
        ma=max(a[b[i]],ma);
        sum+=a[b[i]];
    }
    if(sum>ma*2) ans++;
}
void dfs(int p,int k){
    if(p<=k){
        for(int i=1;i<=n;i++){
            if(f[i]==false){
                b[p]=i;
                f[i]=true;
                dfs(p+1,k);
                f[i]=false;
            }
        }
    }else{

        check(k);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=3;i<=n;i++){
        dfs(1,i);
    }
    cout<<ans/2;
    return 0;
}

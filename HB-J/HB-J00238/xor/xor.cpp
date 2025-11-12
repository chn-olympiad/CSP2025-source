#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500005;
int n,m,a[N],ans=-1e9,l[N],mem[N];
int dfs(int pos){
    if(pos>n) return 0;
    int ans=0;
    if(mem[pos]) return mem[pos];
    if(l[pos]!=-1){
        int tmp1=dfs(l[pos]+1);
        int tmp2=dfs(pos+1);
        mem[pos]=max(tmp1+1,tmp2);
    }else{
        mem[pos]=dfs(pos+1);
    }
    return mem[pos];
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        ll num=0;
        for(int j=i;j<=n;j++){
            num^=a[j];
            if(num==m){
                l[i]=j;
                break;
            }
        }
        if(l[i]==0) l[i]=-1;
    }
    cout<<dfs(1);
    return 0;
}

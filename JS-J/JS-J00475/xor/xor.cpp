#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=2e6;
int k,n,x,a[N],ans[N];
vector<int>v[M];
int st[N],en[N],t;
map<int,int>mp;
struct node{
    int s,e;
};
int f[N];
int dfs(int x,int sum){
    int res=0;
    for(int i=1;i<=t;i++){
        if(st[i]>x)dfs(mp[st[i]],sum+1),res=1;
    }
    if(!res)return sum;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        st[++t]=i;
        mp[i]=i;
        if(i==1)a[i]=x;
        else a[i]=a[i-1]^x;
        v[a[i]].push_back(i);
    }
    for(int i=1;i<=n;i++){
        for(auto j:v[a[i]^k]){
            if(i<j){
                st[++t]=i+1;
                en[t]=j;
                mp[i+1]=j;
            }
        }
    }
    //for(int i=1;i<=t;i++)cout<<st[i];
    cout<<dfs(0,0);
    return 0;
}

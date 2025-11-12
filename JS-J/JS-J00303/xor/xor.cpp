#include<bits/stdc++.h>
using namespace std;
int n,k,tot,ans,s[500005],f[500005];
struct node{
    int st,ed;
}w[500005];
bool cmp(node a,node b){
    return a.ed<b.ed;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    memset(f,-1,sizeof(f));
    f[0]=0;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        s[i]=a^s[i-1];
        int t=s[i]^k;
        if(f[t]!=-1){
            tot++;
            w[tot].st=f[t]+1;
            w[tot].ed=i;
            f[t]=-1;
        }
        else f[s[i]]=i;
    }
    stable_sort(w+1,w+tot+1,cmp);
    int led=-1;
    for(int i=1;i<=tot;i++){
        if(w[i].st>led){
            ans++;
            led=w[i].ed;
        }
    }
    cout<<ans;
    return 0;
}
//Hope to have a good ending.
//Please give me more points on it.
//I wish everyone in HZ or KM have a good ending.
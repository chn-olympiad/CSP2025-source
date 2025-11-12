#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,k;
int a[N],sum[N],yu[N];
struct node{
    int lf,rg;
}sett[N];
bool vis[N];
int num=0,num1=0;
map<int,vector<int>> mp;
bool cmp(node x,node y){
    if(x.rg!=y.rg) return x.rg<y.rg;
    return x.lf<y.lf;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    mp[0].push_back(0);
    yu[++num]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]^a[i];
        if(!mp.count(sum[i])) yu[++num]=sum[i];
        mp[sum[i]].push_back(i);
    }
    for(int i=0;i<=num;i++){
        for(int j=0;j<mp[yu[i]].size();j++){
            for(int p=0;p<mp[yu[i]^k].size();p++){

                if(mp[yu[i]][j]<mp[yu[i]^k][p]){
                sett[++num1].lf=mp[yu[i]][j]+1;
                sett[num1].rg=mp[yu[i]^k][p];
                }
                else{
                    sett[++num1].lf=mp[yu[i]^k][p]+1;
                    sett[num1].rg=mp[yu[i]][j];
                }
            }
        }
    }
    sort(sett+1,sett+1+num1,cmp);
    long long ans=0;
    int en=-1;
    for(int i=1;i<=num1;i++){
        if(sett[i].lf>en){
            en=sett[i].rg;
            //cout<<sett[i].lf<<" "<<sett[i].rg<<endl;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}

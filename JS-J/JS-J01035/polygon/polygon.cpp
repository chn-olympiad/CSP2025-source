#include<bits/stdc++.h>
using namespace std;
int a[5005],cnt=0;int n;
bool vis[5005];
pair<bool,int> chs(int k,int c,int b,int s){
    pair<bool,int> t;
    if(c>=3&&(s>2*b)){
        t.first=1;
        //cout<<b<<' '<<s<<endl;
    }else t.first=0;
    vis[k]=1;
    int ct=0,bb=b,ss=s;
    for(int i=k+1;i<=n;i++){
      if(!vis[i]){
         ss+=a[i],bb=max(bb,a[i]);
       pair<bool,int> p= chs(i,c+1,bb,ss);
       ct+=p.second+p.first;
      }
    }vis[k]=0;
    t.second=ct;
    return t;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }sort(a+1,a+n+1);
    for(int i=1;i<=n-2;i++){
        pair<bool,int> t=chs(i,1,a[i],a[i]);
        cnt=(cnt+t.first+t.second)/2%998244353;
    }
    cout<<cnt;
    return 0;
}
//cnt=(cnt+1)%998244353;

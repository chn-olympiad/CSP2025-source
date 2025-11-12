#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
    int s=0,w=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')w=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){s=s*10+ch-'0';ch=getchar();}
    return s*w;
}
const int N=2e5+5;
array<int,3>a[N];
pair<int,int>get(array<int,3>x){
    vector<pair<int,int>>v;v.push_back({x[0],0});v.push_back({x[1],1});v.push_back({x[2],2});
    sort(v.begin(),v.end());return{v[2].second,v[1].second};
}
void solve(){
    int n=read(),ans=0,s[3]={0,0,0};
    for(int i=1;i<=n;i++)a[i]={read(),read(),read()};
    sort(a+1,a+n+1,[](array<int,3>x,array<int,3>y){
        pair<int,int>a=get(x);pair<int,int>b=get(y);
        return x[a.first]-x[a.second]>y[b.first]-y[b.second];
    });
    for(int i=1;i<=n;i++){
        pair<int,int>tmp=get(a[i]);
        // cout<<a[i][tmp.first]<<" "<<a[i][tmp.second]<<"\n";
        if(s[tmp.first]<n/2)ans+=a[i][tmp.first],s[tmp.first]++;
        else ans+=a[i][tmp.second],s[tmp.second]++;
    }cout<<ans<<"\n";
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t=read();
    while(t--)solve();
    return 0;
}
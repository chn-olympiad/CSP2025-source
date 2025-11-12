#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],b[500010];
vector<pair<int,int> > v;
map<int,int> w;
bool lu(pair<int,int> x,pair<int,int> y){
    if(x.second!=y.second) return x.second<y.second;
    return x.first>y.first;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    v.clear();
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    b[n+1]=0;
    for(int i=n;i>0;i--)
        b[i]=a[i]^b[i+1];
    w[0]=n+1;
    for(int i=n;i>0;i--){
        if(w.count(b[i]^k)){
            v.push_back({i,w[b[i]^k]-1});
        }
        w[b[i]]=i;
    }
    sort(v.begin(),v.end(),lu);
    int t=0,ans=0,r=0;
    while(t<(int)v.size()){
        t++;
        while(t<=(int)v.size()){
            if(v[t-1].first>r) break;
            t++;
        }
        if(t<=(int)v.size()){
            ans++;
            r=v[t-1].second;
        }
        //printf("%d %d\n",t,r);
    }
    printf("%d\n",ans);
    return 0;
}

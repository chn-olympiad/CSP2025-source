#include<bits/stdc++.h>
using namespace std;
int a[5002];
long long sum=0,ans=0;
set<int>s;
void dfs(set<int>::iterator ds,int e){
    if(a[e]*2<sum){
        ans++;
        ans%=998244353;
    }if(s.size()==1)return;
    for(auto it=ds;it!=s.end();it++){
        int i=*it;
        auto td=it;
        td++;
        sum-=a[i];
        s.erase(i);
        auto t=s.end();
        t--;
        dfs(td,*t);
        it=s.insert(i).first;
        sum+=a[i];
    }return;
}int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
        sum+=a[i];
        s.insert(i);
    }sort(a,a+n);
    dfs(s.begin(),a[n-1]);
    printf("%lld\n",ans);
    return 0;
}
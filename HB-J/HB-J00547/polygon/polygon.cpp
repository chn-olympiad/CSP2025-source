#include <bits/stdc++.h>
using namespace std;
int n,book[5005],a[5005],mod=998244353,ans;
vector<int> e;
void func(int step,int cnt,int maxn,int sum){
    if(step>=3){
        if(sum>2*maxn)
            ans++,ans%=mod;
    }
    for(int i=cnt+1;i<=n;i++){
        if(book[i])
            continue;
        book[i]=1;
        e.push_back(a[i]);
        func(step+1,i,(a[i]>maxn)? a[i]:maxn,sum+a[i]);
        book[i]=0;
        e.pop_back();
    }
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++){
        book[i]=1;
        e.push_back(a[i]);
        func(1,i,a[i],a[i]);
        book[i]=0;
        e.pop_back();
    }
    cout<<ans;
    return 0;
}

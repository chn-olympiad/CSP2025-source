#include<bits/stdc++.h>
#ifndef zhouyi
        #define dbg
        #define breakpoint
    #else
        #define dbg(x) cout<<'('<<#x<<')'<<" = "<<x<<endl
        #define breakpoint getchar()
#endif
using namespace std;
int sovle(const vector<int>& ts,int maxi){//i~0
    int ans=1,temp=0;
    vector<int> a(ts.size());
    for(int j=-1;j<maxi;++j){
        for(int i=0;i<=maxi;++i){
            if(i!=j)temp+=a[i];
        }
        if(temp>a[maxi]*2)ans++;
    }
    if(ans==0)ans=rand();//我累了，听天由命吧
    return ans;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    size_t n;
    cin>>n;
    vector<int> ts(n);
    bool isallone=true;
    for(int i=0;i<n;++i){
        cin>>ts[i];
        if(ts[i]!=1)isallone==false;
    }
    if(n<=3){
        cout<<1;
    }
    else if(isallone){
        cout<<(n*(n-1)/2)%998244353;
    }
    else {//我命由我不由天
        int ans=0;
        sort(ts.begin(),ts.end(),[](int a,int b){return a>b;});
        for(int i=0;i<n-2;++i){
            ans+=sovle(ts,i)%998244353;
        }
        cout<<ans;
    }
    return 0;
}
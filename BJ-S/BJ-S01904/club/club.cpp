#include<bits/stdc++.h>
using namespace std;
int T,n,num1,num2,num3,ans;
struct TT{
    int a,b,c;
}a[100005];
struct cmp{
    bool operator()(int x,int y){
        return x>y;
    }
};
priority_queue<int,vector<int>,cmp>d[5];
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while(T--){
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            int x,y,z,maxn;
            cin>>x>>y>>z;
            maxn=max({x,y,z});
            ans+=maxn;
            if(maxn==x){
                d[1].push(x-max(y,z));
            }else if(maxn==y){
                d[2].push(y-max(x,z));
            }else{
                d[3].push(z-max(x,y));
            }
        }
        for(int i=1;i<=3;i++){
            while(!d[i].empty()&&d[i].size()>n/2){
                ans-=d[i].top();
                d[i].pop();
            }
            while(!d[i].empty())d[i].pop();
        }
        cout<<ans<<endl;
    }
    return 0;
}//g++ -Wall -std=c++14 -fsanitize=address,undefined,leak -O2 1.cpp -o 1
//time ./1

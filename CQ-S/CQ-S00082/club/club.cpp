#include<bits/stdc++.h>
const int N=1e5+5;
int n,a[N][3];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    std::ios::sync_with_stdio(false),std::cin.tie(nullptr),std::cout.tie(nullptr);
    int T; std::cin>>T;
    for(;T--;){
        std::cin>>n;
        for(int i=1;i<=n;i++) for(int j:{0,1,2}) std::cin>>a[i][j];
        std::vector<int> st[3];
        int ans=0;
        for(int i=1;i<=n;i++){
            if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]) st[0].push_back(i),ans+=a[i][0];
            else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]) st[1].push_back(i),ans+=a[i][1];
            else st[2].push_back(i),ans+=a[i][2];
        }
        std::priority_queue<int,std::vector<int>,std::less<int> > q;
        if((int)st[0].size()>n/2){
            for(auto i:st[0]) q.push(std::max(a[i][1]-a[i][0],a[i][2]-a[i][0]));
            for(;(int)q.size()>n/2;q.pop()) ans+=q.top();
        }else if((int)st[1].size()>n/2){
            for(auto i:st[1]) q.push(std::max(a[i][0]-a[i][1],a[i][2]-a[i][1]));
            for(;(int)q.size()>n/2;q.pop()) ans+=q.top();
        }else if((int)st[2].size()>n/2){
            for(auto i:st[2]) q.push(std::max(a[i][0]-a[i][2],a[i][1]-a[i][2]));
            for(;(int)q.size()>n/2;q.pop()) ans+=q.top();
        }
        std::cout<<ans<<"\n";
    }
    return 0;
}


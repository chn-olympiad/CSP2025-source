#include<bits/stdc++.h>
using namespace std;
namespace FileIO{
    void Test(string s){
        freopen((s+".in").c_str(),"r",stdin);
        freopen("test.out","w",stdout);
    }
    void File(string s){
        freopen((s+".in").c_str(),"r",stdin);
        freopen((s+".out").c_str(),"w",stdout);
    }
}
int n;
int a[100005][5];
int pri[100005][5];
void Work(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        priority_queue<pair<int,int>> tmp;
        scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
        tmp.push({a[i][1],1});
        tmp.push({a[i][2],2});
        tmp.push({a[i][3],3});
        pri[i][1]=tmp.top().second;
        tmp.pop();
        pri[i][2]=tmp.top().second;
        tmp.pop();
        pri[i][3]=tmp.top().second;
    }
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> p[5]={};
    int ans=0;
    for(int i=1;i<=n;i++){
        p[pri[i][1]].push({a[i][pri[i][1]]-a[i][pri[i][2]],{i,1}});
        ans+=a[i][pri[i][1]];
        int cur=i,cpr=1;
        while(p[pri[cur][cpr]].size()>n/2){
            cur=p[pri[cur][cpr]].top().second.first;
            cpr=p[pri[cur][cpr]].top().second.second;
            // printf("try(%d,%d)\n",cur,cpr);
            ans-=a[cur][pri[cur][cpr]];
            p[pri[cur][cpr]].pop();
            if(cpr<3){
                p[pri[cur][cpr+1]].push({a[cur][pri[cur][cpr+1]]-a[cur][pri[cur][cpr+2]],{cur,cpr+1}});
                ans+=a[cur][pri[cur][cpr+1]];
                cpr++;
            }
        }
    }
    printf("%d\n",ans);
}
int main(){
    // FileIO::Test("club/club5");
    FileIO::File("club");
    int t=1;
    scanf("%d",&t);
    while(t--){
        Work();
    }
    clog<<clock()*1.0/CLOCKS_PER_SEC;
    return 0;
}
/*
g++ test.cpp -o test -fsanitize=address,undefined -g
g++ test.cpp -o test -O2
*/
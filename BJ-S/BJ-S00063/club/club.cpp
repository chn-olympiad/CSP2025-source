#include <iostream>
#include <queue>
using namespace std;
priority_queue <int,vector<int>,greater<int>> q[5];
int cnt_people[5];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t; cin>>t;
    while(t--){
        cnt_people[1]=0; cnt_people[2]=0; cnt_people[3]=0;
        while(!q[1].empty()) q[1].pop();
        while(!q[2].empty()) q[2].pop();
        while(!q[3].empty()) q[3].pop();
        int sum=0;
        int ans=0;
        int n; cin>>n;
        for(int i=1;i<=n;i++)
        {
            int a1,a2,a3; cin>>a1>>a2>>a3;
            sum+=max(a1,max(a2,a3));
            if(max(a1,max(a2,a3))==a1){cnt_people[1]++; q[1].push(a1-max(a2,a3)); }
            else if(max(a1,max(a2,a3))==a2){cnt_people[2]++; q[2].push(a2-max(a1,a3));}
            else{cnt_people[3]++; q[3].push(a3-max(a2,a1));}
        }
        int srl;
        if(max(cnt_people[1],max(cnt_people[2],cnt_people[3]))==cnt_people[1]) srl=1;
        if(max(cnt_people[1],max(cnt_people[2],cnt_people[3]))==cnt_people[2]) srl=2;
        if(max(cnt_people[1],max(cnt_people[2],cnt_people[3]))==cnt_people[3]) srl=3;
        while(cnt_people[srl]>(n>>1)){
            cnt_people[srl]--;
            sum-=q[srl].top();
            q[srl].pop();
        }
        cout<<sum<<endl;
    }
}

#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
typedef long long ll;
ll t1,n,a[100005][10],sz1,sz2,sz3;
priority_queue<pair<ll,ll>> team1,team2,team3;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t1;
    while(t1--){
        sz1=0;
        sz2=0;
        sz3=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        for(int i=1;i<=n;i++){
            if(a[i][1]>=max(a[i][2],a[i][3])){
                team1.push({-1*(a[i][1]-max(a[i][2],a[i][3])),i});
                sz1++;
            }else if(a[i][2]>=max(a[i][1],a[i][3])){
                team2.push({-1*(a[i][2]-max(a[i][1],a[i][3])),i});
                sz2++;
            }else if(a[i][3]>=max(a[i][1],a[i][2])){
                team3.push({-1*(a[i][3]-max(a[i][1],a[i][2])),i});
                sz3++;
            }
            if(sz1>n/2){
                sz1--;
                ll now=team1.top().second;
                team1.pop();
                if(a[now][2]>=a[now][3]){
                    sz2++;
                    team2.push({-1*(a[now][2]-a[now][3]),now});
                }else{
                    sz3++;
                    team3.push({-1*(a[now][3]-a[now][2]),now});
                }
            }
            if(sz2>n/2){
                sz2--;
                ll now=team2.top().second;
                team2.pop();
                if(a[now][1]>=a[now][3]){
                    sz1++;
                    team1.push({-1*(a[now][1]-a[now][3]),now});
                }else{
                    sz3++;
                    team3.push({-1*(a[now][3]-a[now][1]),now});
                }
            }
            if(sz3>n/2){
                sz3--;
                ll now=team3.top().second;
                team3.pop();
                if(a[now][2]>=a[now][1]){
                    sz2++;
                    team2.push({-1*(a[now][2]-a[now][1]),now});
                }else{
                    sz1++;
                    team1.push({-1*(a[now][1]-a[now][2]),now});
                }
            }
        }
        ll allans=0;
        while(!team1.empty()){
            allans+=a[team1.top().second][1];
            team1.pop();
        }
        while(!team2.empty()){
            allans+=a[team2.top().second][2];
            team2.pop();
        }
        while(!team3.empty()){
            allans+=a[team3.top().second][3];
            team3.pop();
        }
        cout<<allans<<endl;
    }
    return 0;
}

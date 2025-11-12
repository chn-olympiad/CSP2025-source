#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#define pii pair<int,int>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    int T;
    cin >> T;
    while(T--){
        int n,ans=0;
        cin >> n;
        for(int i=0;i<n;i++){
            priority_queue<pii> maxt;
            priority_queue<int> pq[3];
            int t;
            for(int j=0;j<3;j++){
                cin >> t;
                maxt.push(make_pair(t,j));
            }
            pii a=maxt.top();
            ans+=a.first;
            maxt.pop();
            pii b=maxt.top();

            int d=a.first-b.first;
            int aim=a.second;
            pq[aim].push(-d);

            if(pq[aim].size()>=n/2){
                ans+=pq[aim].top();
                pq[aim].pop();
            }
        }
        cout << ans << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

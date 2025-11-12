#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//first means "val" and second means "id"
ll T,n,res,d[(int)1e5+5][4];//Temp
pair<ll,ll>o[4];// Temp
pair<ll,ll>ip[(int)1e5+5][5]; //i and rk
unordered_map<ll,ll>q;//count people
unordered_map<ll,ll>t;//who want to join what club
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>qp[3];// hungry's queue
void insert(ll r){
//    cout << r << '\n';
    for(int i = 1;i<=3;i++){
        pair<int,int>dq = ip[r][i];
        if(q[dq.second]<n/2){
            q[dq.second]++;
            res+=dq.first;
            t[r]=i;
            qp[dq.second].push({dq.first-ip[r][i+1].first,r});
            return;
        }
        else{
            pair<ll,ll>lst = qp[dq.second].top();
            pair<ll,ll>lst_ifm = ip[lst.second][t[lst.second]];
            if(dq.first-ip[r][i+1].first>lst.first){
                qp[dq.second].pop();
                res-=lst_ifm.first;
                qp[dq.second].push({dq.first-ip[r][i+1].first,r});
                res+=dq.first;
                t[r]=i;
                t[lst.second]=0;
                insert(lst.second);
                return;
            }
            else{
                continue;
            }
        }
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> T;
    while(T--){
        cin >> n;
        res = 0;
        q.clear();
        t.clear();
        for(int i = 1;i<=3;i++){
             while(!qp[i].empty()){
                qp[i].pop();
            }
        }

        for(int i = 1;i<=n;i++){
            cin >> d[i][1] >> d[i][2] >> d[i][3];
            o[1] = {d[i][1],1};
            o[2] = {d[i][2],2};
            o[3] = {d[i][3],3};
            sort(o+1,o+4,greater<>());
            ip[i][1] = o[1];
            ip[i][2] = o[2];
            ip[i][3] = o[3];
        }
        for(int i = 1;i<=n;i++){
            insert(i);
        }
        cout << res << '\n';
    }
    return 0;
}

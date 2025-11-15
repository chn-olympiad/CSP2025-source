#include <bits/stdc++.h>
using namespace std;
struct pencil{
    int u;
    int v;
    int val;
};
vector<pencil> road;
int col[10005]={0};
bool cmp(pencil a,pencil b){
    return a.val>b.val;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w", stdout);
    //greedy and assume k=0
    int n,m,k;
    cin>>n>>m>>k;
    int temp1,temp2,temp3;
    pencil temp;
    int ans=0;
    for(int i=0;i<m;i++){
        cin>>temp1>>temp2>>temp3;
        temp.u=temp1;
        temp.v=temp2;
        temp.val=temp3;
        road.push_back(temp);
        ans+=temp3;
        col[temp1]++;
        col[temp2]++;
    }
    sort(road.begin(),road.end(),cmp);
    for(int i=0;i<m;i++){
        cout<<road[i].u<<" "<<road[i].v<<" "<<road[i].val<<" "<<col[road[i].u]<<" "<<col[road[i].v]<<endl;
        if(col[road[i].u]>1 && col[road[i].v]>1){
            ans-=road[i].val;
            col[road[i].u]--;
            col[road[i].v]--;
            cout<<ans<<" "<<endl;
        }

    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
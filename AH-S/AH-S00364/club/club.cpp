#include<bits/stdc++.h>
using namespace std;
int T,n,a[100010][4],maxi[100010],midi[100010],mini[100010];
priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int>> >q[4];
int add(int k,int h){
    int cha;
    if(h==maxi[k])cha=a[k][maxi[k]]-a[k][midi[k]];
    else cha=a[k][midi[k]]-a[k][mini[k]];
    if(q[h].size()<n/2)q[h].push(make_pair(cha,k));
    else {
        pair<int,int> x=q[h].top();
        if(x.first<cha){
            q[h].pop();
            q[h].push(make_pair(cha,k));
            if(h==maxi[x.second])add(x.second,midi[x.second]);
            else add(x.second,mini[x.second]);
        }
        else {
            if(h==maxi[k])add(k,midi[k]);
            else add(k,mini[k]);
        }
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>T;
    while(T--){
        int ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            int maxx=max(a[i][1],max(a[i][2],a[i][3]));
            int minn=min(a[i][1],min(a[i][2],a[i][3]));
            for(int j=1;j<=3;j++){
                if(a[i][j]==maxx){maxi[i]=j;break;}
            }
            for(int j=1;j<=3;j++){
                if(a[i][j]==minn and j!=maxi[i]){mini[i]=j;break;}
            }
            midi[i]=6-maxi[i]-mini[i];
        }
        for(int i=1;i<=n;i++){
            add(i,maxi[i]);
        }
        for(int i=1;i<=3;i++){
             while(q[i].size()){
                ans+=a[q[i].top().second][i];
                q[i].pop();
            }

        }
        cout<<ans<<endl;
    }
    return 0;
}

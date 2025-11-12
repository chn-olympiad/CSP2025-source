#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
struct node{
    int s;
    int id;
    friend bool operator <(node X,node Y){
        return X.s<Y.s;
    }
    friend bool operator >(node X,node Y){
        return X.s>Y.s;
    }
}a[100005][3];
struct peo{
    int id;
    friend bool operator <(peo X,peo Y){
        return a[X.id][1].s-a[X.id][2].s<a[Y.id][1].s-a[Y.id][2].s;
    }
    friend bool operator >(peo X,peo Y){
        return a[X.id][1].s-a[X.id][2].s>a[Y.id][1].s-a[Y.id][2].s;
    }
};
int main(){
    ios::sync_with_stdio(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        priority_queue<peo,vector<peo>,less<peo> > pq[3];
        int n;
        cin>>n;
        long long ans=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=2;j++){
                cin>>a[i][j].s;
                a[i][j].id=j;
            }
            sort(a[i],a[i]+3);
            pq[a[i][2].id].push({i});
            ans+=a[i][2].s;
        }
        int t=-1;
        if(pq[0].size()>n/2){
            t=0;
        }
        else if(pq[1].size()>n/2){
            t=1;
        }
        else if(pq[2].size()>n/2){
            t=2;
        }
        if(t!=-1){
            while(pq[t].size()>n/2){
                int q=pq[t].top().id;
                pq[t].pop();
                pq[a[q][1].id].push({q});
                ans+=a[q][1].s-a[q][2].s;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}

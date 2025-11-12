#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <array>
using namespace std;
const int N=1e+5+5;
struct Node{
    array<pair<int,int>,3> a;
    inline void sort(){
        for(int i=0;i<3;i++){
            for(int j=2;j>=i;j--){
                if(a[j].second>a[i].second)
                    swap(a[j],a[i]);
            }
        }
    }
};
array<Node,N> a;
Node nul;
struct w{
    int id,index,group,siz;
    int nxt(){
        if(index==2)return 1e+9;
        return a[id].a[index].second-a[id].a[index+1].second;
    }
    bool operator<(const w &b)const{
        return this->siz<b.siz;
    }
    const bool operator>(const w &b)const{
        int nxta,nxtb;
        if(index==2)nxta= 1e+9;
        nxta= a[id].a[index].second-a[id].a[index+1].second;
        if(b.index==2)nxtb= 1e+9;
        nxtb= a[b.id].a[b.index].second-a[b.id].a[b.index+1].second;
        return nxta>nxtb;
    }
};
inline void work(){
    a.fill(nul);
    int n,ans=0;
    cin>>n;
    priority_queue<w> pq;
    array<priority_queue<w,vector<w>,greater<w>>,3> buc;
    array<int, 3> cnt;
    cnt.fill(0);
    for(int i=1;i<=n;i++){
        cin>>a[i].a[0].second>>a[i].a[1].second>>a[i].a[2].second;
        a[i].sort();
        pq.push({i,0,a[i].a[0].first,a[i].a[0].second});
    }
    while(!pq.empty()){
        w t=pq.top();
        pq.pop();
        if(cnt[t.group]<n/2){
            cnt[t.group]++;
            ans+=t.siz;
            buc[t.group].push(t);
        }
        else{
            w tmp=buc[t.group].top();
            if(t.nxt()>tmp.nxt()){
                buc[t.group].pop();
                ans-=tmp.siz;
                cnt[t.group]--;
                pq.push(t);
                pq.push({tmp.id,tmp.index+1,a[tmp.id].a[tmp.index+1].first,a[tmp.id].a[tmp.index+1].second});
            }
            else
                pq.push({t.id,t.index+1,a[t.id].a[t.index+1].first,a[t.id].a[t.index+1].second});
        }
    }
    cout<<ans<<endl;
}
int main(void){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    for(int i=0;i<3;i++){
        nul.a[i].first=i;
        nul.a[i].second=0;
    }
    int T;
    cin>>T;
    while(T--)work();
    return 0;
}
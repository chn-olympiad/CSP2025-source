#include<bits/stdc++.h>

using namespace std;

//typedef long long ll;

const int N=100000;

struct Node {
    array<int,4> val;
    int id;
};

struct Node1 {
    int a;
    int b;
    int c;
    int id;
};

int n;
vector<Node> rens;
unordered_map<int,int> csz;
vector<Node1> a;


long long dfs(int x,int ga_size,int gb_size,int gc_size) {
    if(x>n) {
        return 0;
    }
    long long maxans=0;
    if(ga_size<(n/2)) {
        maxans=max(maxans,dfs(x+1,ga_size+1,gb_size,gc_size)+1ll*a[x].a);
    }
    if(gb_size<(n/2)) {
        maxans=max(maxans,dfs(x+1,ga_size,gb_size+1,gc_size)+1ll*a[x].b);
    }
    if(gc_size<(n/2)) {
        maxans=max(maxans,dfs(x+1,ga_size,gb_size,gc_size+1)+1ll*a[x].c);
    }
    return maxans;
}


int other_group(int a,int b) {
    bool tmp[4];
    tmp[1]=tmp[2]=tmp[3]=0;
    tmp[a]=1;
    tmp[b]=1;
    for(int i=1; i<=3; i++) {
        if(!tmp[i]) {
            return 1;
        }
    }
}

int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--) {
        long long ans=0;
        //-换组最小代价 换组号 点编号
        priority_queue<array<int,3>> pq[4];
        rens.clear();
        csz.clear();
        a.clear();
        cin>>n;
        rens.push_back({-1,-1,-1,-1});
        a.push_back({-1,-1,-1,-1});
        for(int i=1; i<=n; i++) {
            int ia,ib,ic;
            cin>>ia>>ib>>ic;
            a.push_back({ia,ib,ic,i});
            if(n<=10){
                continue;
            }
            rens.push_back({{0,ia,ib,ic},i});
            if((ia>ib)&&(ia>ic)) {
                int djb=ia-ib;
                int djc=ia-ic;
                if(djb<=djc) {
                    pq[1].push({-djb,2,i});
                } else {
                    pq[1].push({-djc,3,i});
                }
                csz[i]=1;
                ans+=1ll*ia;
            } else if((ib>ia)&&(ib>ic)) {
                int dja=ib-ia;
                int djc=ib-ic;
                if(dja<=djc) {
                    pq[2].push({-dja,1,i});
                } else {
                    pq[2].push({-djc,3,i});
                }
                csz[i]=2;
                ans+=1ll*ib;
            } else if((ic>ia)&&(ic>ib)) {
                int dja=ic-ia;
                int djb=ic-ib;
                if(dja<=djb) {
                    pq[3].push({-dja,1,i});
                } else {
                    pq[3].push({-djb,2,i});
                }
                csz[i]=3;
                ans+=1ll*ic;
            } else {
                int djb=ia-ib;
                int djc=ia-ic;
                if(djb<=djc) {
                    pq[1].push({-djb,2,i});
                } else {
                    pq[1].push({-djc,3,i});
                }
                csz[i]=1;
                ans+=1ll*ia;
            }
        }
        if(n<=10) {
            cout<<dfs(1,0,0,0)<<endl;
            continue;
        }
//        cerr<<1<<endl;
        for(int i=1; i<=3; i++) {
            while(pq[1].size()>(n/2)) {
                auto top=pq[1].top();
                pq[1].pop();
                ans+=1ll*top[0];
                pq[top[1]].push({rens[top[2]].val[csz[top[2]]]-rens[1].val[other_group(1,top[1])],other_group(1,top[1]),top[2]});
            }
            while(pq[2].size()>(n/2)) {
                auto top=pq[2].top();
                pq[2].pop();
                ans+=1ll*top[0];
                pq[top[1]].push({rens[top[2]].val[csz[top[2]]]-rens[1].val[other_group(2,top[1])],other_group(2,top[1]),top[2]});
            }
            while(pq[3].size()>(n/2)) {
                auto top=pq[3].top();
                pq[3].pop();
                ans+=1ll*top[0];
                pq[top[1]].push({rens[top[2]].val[csz[top[2]]]-rens[1].val[other_group(3,top[1])],other_group(3,top[1]),top[2]});
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

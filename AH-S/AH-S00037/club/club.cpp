#include<bits/stdc++.h>
#define int long long 
#define pb push_back
#define rep(i,x,y) for(int i=x;i<=y;i++) 


using namespace std;

int tmp;
int n;
int a[202002][5];
vector<int>s[5];
int id=0;

bool cmp(int x,int y) {
    //int xx=max(a[x][1]*(id!=1),max(a[x][2]*(id!=2),a[x][3]*(id!=3)));
    //int yy=max(a[y][1]*(id!=1),max(a[y][2]*(id!=2),a[y][3]*(id!=3)));
    //选取减少量最xiao的
    int xx=0,yy=0;
    // if(id==1) {
        xx=a[x][id]-max(a[x][(id+1)%3],a[x][(id+2)%3]);
        yy=a[y][id]-max(a[y][(id+1)%3],a[y][(id+2)%3]);
    // }
    return xx<yy;
}
signed main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>tmp;
    while(tmp--) {
        cin>>n;
        s[1].clear();
        s[2].clear();
        s[3].clear();
        rep(i,1,n) {
            rep(j,1,3) {
                cin>>a[i][j];
            }
        }
        /*
        priority_queue<int>x,y,z;
        while(!x.empty()) x.pop();
        while(!y.empty()) y.pop();
        while(!z.empty()) z.pop();
        */
        int x,y,z;
        s[1].clear();
        s[2].clear();
        s[3].clear();
        int ans=0;
        rep(i,1,n) {
            ans+=max(a[i][1],max(a[i][2],a[i][3]));
            if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) {
                s[1].pb(i);
            } else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) {
                s[2].pb(i);
            } else s[3].pb(i);
        }
        int nw1=s[1].size(),nw2=s[2].size(),nw3=s[3].size();
        id=0;
        if(nw1>n/2) {
            id=1;
        } 
        if(nw2>n/2) {
            id=2;
        }
        if(nw3>n/2) {
            id=3;
        }
        if(id) {
            sort(s[id].begin(),s[id].end(),cmp);
            int c=(int)s[id].size()-n/2;
            for(int i=0;i<c;i++) {
                ans-=max(a[s[id][i]][1],max(a[s[id][i]][2],a[s[id][i]][3]));
                ans+=max(a[s[id][i]][(id+1)%3],a[s[id][i]][(id+2)%3]);
            }
        }
        cout<<ans<<'\n';
    }


    return 0;
}
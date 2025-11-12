#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

const int MAXN=1e5+10;

struct tmp{
    int num;
    int id;
    bool friend operator < (tmp x,tmp y){
        return x.num>y.num;
    }
};

struct person{
    int t;
    int max;
    int d;
    bool friend operator < (person x,person y){
        return x.max>y.max;
    }
};
person m[MAXN];
priority_queue<int>q[4];

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;

    while(t--){
        int n,ans=0,cnt[4]={0,0,0,0};
        cin>>n;
        for(int i=0;i<n;++i){
            tmp a[4];
            cin>>a[1].num>>a[2].num>>a[3].num;
            a[1].id=1;
            a[2].id=2;
            a[3].id=3;
            sort(a+1,a+4);
            ans+=a[3].num;
            m[i]={a[1].id,a[1].num-a[3].num,a[1].num-a[2].num};
        }
        sort(m,m+n);
        for(int i=0;i<n;++i){
            ++cnt[m[i].t];
            q[m[i].t].push(-m[i].d);
            if((cnt[m[i].t]<<1)>n){
                ans+=q[m[i].t].top();
                q[m[i].t].pop();
            }
            ans+=m[i].max;
        }
        cout<<ans<<endl;
        for(int i=1;i<=3;++i){
            while(!q[i].empty())q[i].pop();
        }
    }

    return 0;
}

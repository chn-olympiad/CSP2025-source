#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
struct node{
    ll d[4];
}a[N];priority_queue<ll>q[4];
ll n;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;cin>>T;while(T--){
        cin>>n;
        for(int j=1;j<=3;j++)while(!q[j].empty())q[j].pop();
        for(int i=1;i<=n;i++){
            cin>>a[i].d[1]>>a[i].d[2]>>a[i].d[3];
            //a[i].mx=max(max(a[i].d[1],a[i].d[2]),a[i].d[3]));
        }
        //sort(a+1,a+n+1);
        ll genshin=0;
        for(int i=1;i<=n;i++){
            ll id=-1,mx=-1e9,mn=-1e9;
            for(int j=1;j<=3;j++){
                if(a[i].d[j]>mx){mn=mx;
                    mx=a[i].d[j];id=j;
                }
                else if(a[i].d[j]>mn){mn=a[i].d[j];}
            }
            q[id].push(mn-mx);
            genshin+=mx;
        }
        for(int j=1;j<=3;j++)
            while(q[j].size()>n/2){
                genshin+=q[j].top();q[j].pop();
            }
        cout<<genshin<<endl;
    }
    return 0;
}
/*
好的那么第一题，感觉就是谭鑫，如果我直接排序，然后调整，那么存在调整一个不如俩？
不存在，如果一个就行，我不如把那俩中的一个调整。
*/

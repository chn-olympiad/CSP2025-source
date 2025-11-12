#include<iostream>
#include<queue>
#include<algorithm>
using std::cin;
using std::cout;
using std::sort;
using std::priority_queue;
const int N=4e5+10;
priority_queue<int>f[3];
struct Node{int val,nb;};
struct NODE{
    Node val1,val2;
    void add(Node x){
        if(x.val>=val1.val)
            val2=val1,val1=x;
        else if(x.val>val2.val)
            val2=x;
    }
}a[N];
inline bool cmp(NODE&x,NODE&y){return x.val1.val>y.val1.val;}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t,n,i,x,y,z,answer;
    cin>>t;
    while(t--){
        cin>>n;
        for(i=1;i<=n;++i){
            cin>>x>>y>>z;
            a[i]={{-1,0},{-1,0}};
            a[i].add({x,0});
            a[i].add({y,1});
            a[i].add({z,2});
        }
        sort(a+1,a+1+n,cmp);
        answer=0;
        for(i=1;i<=n;++i){
            if((int)f[a[i].val1.nb].size()<<1<n){
                answer+=a[i].val1.val;
                f[a[i].val1.nb].push(a[i].val2.val-a[i].val1.val);
            }
            else if(a[i].val2.val-a[i].val1.val<f[a[i].val1.nb].top()){
                answer+=a[i].val1.val;
                answer+=f[a[i].val1.nb].top();
                f[a[i].val1.nb].pop();
                f[a[i].val1.nb].push(a[i].val2.val-a[i].val1.val);
            }
            else answer+=a[i].val2.val;
//            cout<<"text:"<<t<<" i:"<<i<<'\n';
//            if(!f[0].empty())
//			cout<<f[0].size()<<" "<<f[0].top()<<'\n';
//            if(!f[1].empty())
//			cout<<f[1].size()<<" "<<f[1].top()<<'\n';
//            if(!f[2].empty())
//			cout<<f[2].size()<<" "<<f[2].top()<<'\n';
        }
        cout<<answer<<'\n';
        while(!f[0].empty())f[0].pop();
        while(!f[1].empty())f[1].pop();
        while(!f[2].empty())f[2].pop();
    }
    

    return 0;
}

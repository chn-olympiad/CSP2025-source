#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=6e5;
struct node{
    int v,i;
} a[N][5];
int cnt[N];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        //cout<<"Input "<<T<<endl;
        int n;
        cin>>n;
        fill(cnt,cnt+N,0);
        int m=n/2;
        priority_queue<int>pq[5];
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j].v;
                a[i][j].i=j;
            }
            sort(a[i]+1,a[i]+3+1,[](node a,node b){
                return a.v>b.v;
            });
            int x=a[i][1].v,y=a[i][2].v;
            int x1=a[i][1].i,y1=a[i][2].i;
            if(cnt[x1]==m){
                //cout<<i<<" 选择 "<<x1<<" 但是超出限制"<<endl;
                int d=pq[x1].top();
                pq[x1].pop();
                if(d>y-x){
                    //cout<<i<<"更换成功"<<endl;
                    ans+=d;
                    pq[x1].push(y-x);
                    ans+=x;
                }
                else{
                    pq[x1].push(d);
                    //cout<<i<<" 选择 "<<x1<<endl;
                    ans+=y;
                    cnt[y1]++;
                }
            }
            else{
                //cout<<i<<" 选择 "<<y1<<endl;
                pq[x1].push(y-x);
                cnt[x1]++;
                ans+=x;
            }
        }
        cout<<ans<<endl;

    }

    return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/

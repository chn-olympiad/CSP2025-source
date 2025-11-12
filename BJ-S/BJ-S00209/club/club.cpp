#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
priority_queue<int,vector<int>,greater<int> > pq;
int t,n;
int a[N][4];
int b[N];
int t3,t1,t2;
int ans;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        t1=0;
        t2=0;
        t3=0;
        ans=0;
        while(!pq.empty()) pq.pop();
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            int p=max(a[i][1],max(a[i][2],a[i][3]));
            if(a[i][1]==p){
                t1++;
                b[i]=1;
            }
            else if(a[i][2]==p){
                t2++;
                b[i]=2;
            }
            else{
                t3++;
                b[i]=3;
            }
            ans+=p;
        }
        if(t1>(n/2)){
            for(int i=1;i<=n;i++){
                if(b[i]==1){
                    pq.push(a[i][1]-max(a[i][2],a[i][3]));
                }
            }
            while(t1>(n/2)){
                ans-=pq.top();
                pq.pop();
                t1--;
            }
        }
        if(t2>(n/2)){
            for(int i=1;i<=n;i++){
                if(b[i]==2){
                    pq.push(a[i][2]-max(a[i][1],a[i][3]));
                }
            }
            while(t2>(n/2)){
                ans-=pq.top();
                pq.pop();
                t2--;
            }
        }
        if(t3>(n/2)){
            for(int i=1;i<=n;i++){
                if(b[i]==3){
                    pq.push(a[i][3]-max(a[i][2],a[i][1]));
                }
            }
            while(t3>(n/2)){
                ans-=pq.top();
                pq.pop();
                t3--;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}

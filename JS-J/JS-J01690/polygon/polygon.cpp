#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int N=5005;
int a[N],dp[N];
priority_queue<int> q;
priority_queue<int,vector<int>,greater<int>> q1;
const int inf=1e9;
int n;
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int sum=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        bool flag=true;
        q.push(a[i]);
        q1.push(a[i]);
        for(int j=1;j<=i-1;j++){
            q1.push(a[i]+a[j]);
        }
        sum+=a[i];
        int xx=sum;
        while(!q.empty()){
            if(sum<=2*q.top()){
                sum-=q.top();
                q.pop();
            }
            else break;
            if(q.top()==a[i]){
                flag=false;
            }
        }
        if(q.size()==0) flag=false;
        if(flag==true){
            ans++;
            q.push(inf);
            while(!q.empty()){
                stack<int> s;
                int x=q.top();
                if(x!=inf)sum-=x;
                q.pop();
                if(sum<=2*q.top()) break;
                int yy=sum;
                while(!q1.empty()&& q1.top()<x && q1.top()<a[i]){
                    sum-=q1.top();
                    if(sum>2*q.top()) ans++;
                    else break;
                    s.push(q1.top());
                    q1.pop();
                    sum=yy;
                }
                while(!s.empty()){
                    q1.push(s.top());
                    s.pop();
                }
            }
        }
        while(!q.empty()) q.pop();
        for(int j=1;j<=i;j++) q.push(a[j]);
        sum=xx;
    }
    cout<<ans;
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],b[N],c[N],dp[N],dp2[N],dp3[N];
priority_queue<int,vector<int>,greater<int> > q,q2,q3;
void solve(){
    for(int i=0;i<N;++i){
        dp[i]=dp2[i]=dp3[i]=INT_MIN;
    }
    while(!q.empty())q.pop();
    while(!q2.empty())q2.pop();
    while(!q3.empty())q3.pop();
    int n;cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i]>>b[i]>>c[i];
    }
    int sum=n/2,suma=0,sumb=0,sumc=0,ans=0;
    dp[0]=dp2[0]=dp3[0]=0;
    for(int i=1;i<=n;++i){
            //cout<<sum<<" "<<sumb<<" "<<suma<<" "<<sumc<<" "<<q.size()<<endl;
        if(suma==sum){
            dp[i]=max(dp[i-1]-q.top()+a[i],max(dp2[i-1]+a[i],dp3[i-1]+a[i]));
            //cout<<"YES";
        }
        else{
            dp[i]=max(dp[i-1]+a[i],max(dp2[i-1]+a[i],dp3[i-1]+a[i]));//cout<<"!";
        }
        if(sumb==sum){
            dp2[i]=max(dp2[i-1]-q2.top()+b[i],max(dp[i-1]+b[i],dp3[i-1]+b[i]));//cout<<"N";
        }
        else{
            dp2[i]=max(dp2[i-1]+b[i],max(dp[i-1]+b[i],dp3[i-1]+b[i]));//cout<<"A";
        }
        if(sumc==sum){
            dp3[i]=max(dp3[i-1]-q3.top()+c[i],max(dp2[i-1]+c[i],dp[i-1]+c[i]));//cout<<"b";
        }
        else{
            dp3[i]=max(dp3[i-1]+c[i],max(dp[i-1]+c[i],dp2[i-1]+c[i]));
        }
        int u=max(dp[i],max(dp2[i],dp3[i]));
        if(u==dp[i] and suma<sum)suma++,q.push(a[i]-max(b[i],c[i]));
        else if(u==dp2[i] and sumb<sum)sumb++,q2.push(b[i]-max(a[i],c[i]));
        else if(u==dp3[i] and sumc<sum)sumc++,q3.push(c[i]-max(b[i],a[i]));
        else if(u==dp[i] and dp[i]==dp[i-1]-q.top()+a[i]){
            q.pop();q.push(a[i]-max(b[i],c[i]));
        }
        else if(u==dp2[i] and dp2[i]==dp2[i-1]-q2.top()+b[i]){
            q2.pop();q2.push(b[i]-max(a[i],c[i]));
        }
        else if(u==dp3[i] and dp3[i]==dp3[i-1]-q3.top()+c[i]){
            q3.pop();q3.push(c[i]-max(a[i],b[i]));
        }
        ans=u;
        //cout<<ans<<endl;
        //cout<<ans<<" "<<q.top()<<" "<<q2.top()<<" "<<q3.top()<<endl;
    }
    cout<<ans<<"\n";
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}

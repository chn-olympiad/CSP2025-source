#include<bits/stdc++.h>
using namespace std;
typedef pair<pair<int,int>,pair<int,int> > Ppp;
int t,ans,n,a[100005],b[100005],c[100005],f[2][100005],dp[2][205][205];
priority_queue<Ppp,vector<Ppp>,greater<Ppp> > q1,q2,q3;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        ans=0;
        int flag1=1,flag2=1;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            if(b[i]!=0||c[i]!=0){
                flag1=0;
            }
            if(c[i]!=0){
                flag2=0;
            }
        }
        if(flag1){
            sort(a+1,a+1+n,cmp);
            for(int i=1;i<=n/2;i++){
                ans+=a[i];
            }
            cout<<ans<<'\n';
        }
        else if(flag2){
            memset(f,0,sizeof f);
            for(int i=1;i<=n;i++){
                for(int j=0;j<=i;j++){
                    f[i%2][j]=0;
                }
                for(int j=1;j<=i;j++){
                    f[i%2][j]=max(f[i%2][j],f[(i-1)%2][j-1]+a[i]);
                }
                for(int j=0;j<i;j++){
                    f[i%2][j]=max(f[i%2][j],f[(i-1)%2][j]+b[i]);
                }
            }
            cout<<f[n%2][n/2]<<'\n';
        }
        else if(n<=200){
            memset(dp,0,sizeof dp);
            for(int i=1;i<=n;i++){
                for(int l1=0;l1<=i;l1++){
                    for(int l2=0;l2<=i-l1;l2++){
                        int l3=i-l1-l2;
                        dp[i%2][l1][l2]=0;
                        if(l1>0){
                            dp[i%2][l1][l2]=max(dp[i%2][l1][l2],dp[(i-1)%2][l1-1][l2]+a[i]);
                        }
                        if(l2>0){
                            dp[i%2][l1][l2]=max(dp[i%2][l1][l2],dp[(i-1)%2][l1][l2-1]+b[i]);
                        }
                        if(l3>0){
                            dp[i%2][l1][l2]=max(dp[i%2][l1][l2],dp[(i-1)%2][l1][l2]+c[i]);
                        }
                    }
                }
            }
            for(int l1=0;l1<=n;l1++){
                for(int l2=0;l2<=n-l1;l2++){
                    int l3=n-l1-l2;
                    if((l1<=(n/2))&&(l2<=(n/2))&&(l3<=(n/2))){
                        ans=max(ans,dp[n%2][l1][l2]);
                    }
                }
            }
            cout<<ans<<'\n';
        }
        else{
            for(int i=1;i<=n;i++){
                int mx=max(a[i],b[i]);
                mx=max(mx,c[i]);
                if(mx==a[i]){
                    q1.push({{a[i],b[i]},{c[i],i}});
                    if(q1.size()>(n/2)){
                        int x=q1.top().first.second;
                        int y=q1.top().second.first;
                        if(x>y){
                            if(q2.size()<(n/2)){
                                q2.push({{x,q1.top().first.first},{y,q1.top().second.second}});
                            }
                            else{
                                q3.push({{y,q1.top().first.first},{x,q1.top().second.second}});
                            }
                        }
                        else if(x<y){
                            if(q3.size()<(n/2)){
                                q3.push({{y,q1.top().first.first},{x,q1.top().second.second}});
                            }
                            else{
                                q2.push({{x,q1.top().first.first},{y,q1.top().second.second}});
                            }
                        }
                        else{
                            if(q2.size()<q3.size()){
                                q2.push({{x,q1.top().first.first},{y,q1.top().second.second}});
                            }
                            else{
                                q3.push({{y,q1.top().first.first},{x,q1.top().second.second}});
                            }
                        }
                        q1.pop();
                    }
                }
                else if(mx==b[i]){
                    q1.push({{b[i],a[i]},{c[i],i}});
                    if(q2.size()>(n/2)){
                        int x=q2.top().first.second;
                        int y=q2.top().second.first;
                        if(x>y){
                            if(q1.size()<(n/2)){
                                q1.push({{x,q2.top().first.first},{y,q2.top().second.second}});
                            }
                            else{
                                q3.push({{y,x},{q2.top().first.first,q2.top().second.second}});
                            }
                        }
                        else if(x<y){
                            if(q3.size()<(n/2)){
                                q3.push({{y,x},{q2.top().first.first,q2.top().second.second}});
                            }
                            else{
                                q1.push({{x,q2.top().first.first},{y,q2.top().second.second}});
                            }
                        }
                        else{
                            if(q1.size()<q3.size()){
                                q1.push({{x,q2.top().first.first},{y,q2.top().second.second}});
                            }
                            else{
                                q3.push({{y,x},{q2.top().first.first,q2.top().second.second}});
                            }
                        }
                        q2.pop();
                    }
                }
                else{
                    q3.push({{c[i],a[i]},{b[i],i}});
                    if(q3.size()>(n/2)){
                        int x=q3.top().first.second;
                        int y=q3.top().second.first;
                        if(x>y){
                            if(q1.size()<(n/2)){
                                q1.push({{x,y},{q3.top().first.first,q3.top().second.second}});
                            }
                            else{
                                q2.push({{y,x},{q3.top().first.first,q3.top().second.second}});
                            }
                        }
                        else if(x<y){
                            if(q2.size()<(n/2)){
                                q2.push({{y,x},{q3.top().first.first,q3.top().second.second}});
                            }
                            else{
                                q1.push({{x,y},{q3.top().first.first,q3.top().second.second}});
                            }
                        }
                        else{
                            if(q1.size()<q2.size()){
                                q1.push({{x,y},{q3.top().first.first,q3.top().second.second}});
                            }
                            else{
                                q2.push({{y,x},{q3.top().first.first,q3.top().second.second}});
                            }
                        }
                        q3.pop();
                    }
                }
            }
            while(!q1.empty()){
                ans+=q1.top().first.first;
                q1.pop();
            }
            while(!q2.empty()){
                ans+=q2.top().first.first;
                q2.pop();
            }
            while(!q3.empty()){
                ans+=q3.top().first.first;
                q3.pop();
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}

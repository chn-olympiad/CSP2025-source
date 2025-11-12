#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef pair<int,pair<int,int> >piii;
const int N=1e5+10;
int t,n,a[N][3],cnt[3];
long long ans;
priority_queue<piii>q0,q1,q2;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        ans=0;
        cin>>n;
        cnt[0]=cnt[1]=cnt[2]=0;
        for(int i=1;i<=n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        int k=n/2;
        for(int i=1;i<=n;i++){
            if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
                ans+=1ll*a[i][0];
                cnt[0]++;
                if(a[i][1]>a[i][2]){
                    q0.push({a[i][1]-a[i][0],{i,1}});
                }
                else{
                    q0.push({a[i][2]-a[i][0],{i,2}});
                }
            }
            else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
                ans+=1ll*a[i][1];
                cnt[1]++;
                if(a[i][0]>a[i][2]){
                    q1.push({a[i][0]-a[i][1],{i,0}});
                }
                else{
                    q1.push({a[i][2]-a[i][1],{i,2}});
                }
            }
            else{
                ans+=1ll*a[i][2];
                cnt[2]++;
                if(a[i][1]>a[i][0]){
                    q2.push({a[i][1]-a[i][2],{i,1}});
                }
                else{
                    q2.push({a[i][0]-a[i][2],{i,0}});
                }
            }
            if(cnt[0]>k){
                int x=q0.top().x,y=q0.top().y.x,z=q0.top().y.y;
                ans+=x;
                q0.pop();
                cnt[0]--;
                cnt[z]++;
                if(z==1){
                    q1.push({a[y][2]-a[y][1],{y,2}});
                }
                else q1.push({a[y][1]-a[y][2],{y,1}});
            }
            else if(cnt[1]>k){
                int x=q1.top().x,y=q1.top().y.x,z=q1.top().y.y;
                ans+=x;
                q1.pop();
                cnt[1]--;
                cnt[z]++;
            }
            else if(cnt[2]>k){
                int x=q2.top().x,y=q2.top().y.x,z=q2.top().y.y;
                ans+=x;
                q2.pop();
                cnt[2]--;
                cnt[z]++;
            }
        }
        cout<<ans<<"\n";
        while(!q0.empty())q0.pop();
        while(!q2.empty())q2.pop();
        while(!q1.empty())q1.pop();
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int t,n,sum=0;
int a[100005][3],ch[100005],v[100005],s[6];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        sum=0;
        memset(s,0,sizeof(s));
        priority_queue<int,vector<int>,greater<int> > pq;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) {
                ch[i]=1;
                v[i]=a[i][1]-max(a[i][2],a[i][3]);
                s[1]++;
            }else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
                ch[i]=2;
                v[i]=a[i][2]-max(a[i][1],a[i][3]);
                s[2]++;
            }else{
                ch[i]=3;
                v[i]=a[i][3]-max(a[i][2],a[i][1]);
                s[3]++;
            }
            sum+=max({a[i][1],a[i][2],a[i][3]});
        }
        if(s[1]<=n/2&&s[2]<=n/2&&s[3]<=n/2){
            cout<<sum<<endl;
            continue;
        }else{
            int maxx,maxy=max({s[1],s[2],s[3]});
            if(s[1]>=s[2]&&s[1]>=s[3]){
                maxx=1;
            }else if(s[2]>=s[1]&&s[2]>=s[3]){
                maxx=2;
            }else{
                maxx=3;
            }
            for(int i=1;i<=n;i++){
                if(ch[i]==maxx){
                    pq.push(v[i]);
                }
            }
            for(int i=1;i<=maxy-n/2;i++){
                sum=sum-pq.top();
                pq.pop();
            }
            cout<<sum<<endl;
        }
    }
}

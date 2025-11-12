#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[100005],b[100005],c[100005],ans;
int as(int a[],int b[],int c[]){
    int ans=0,t=n/2;
    priority_queue<int> q;
    for(int i=1;i<=n;i++){
        ans+=max(b[i],c[i]);
        q.push(a[i]-max(b[i],c[i]));
    }
    while(q.size()&&t--){
        ans+=q.top();
        q.pop();
    }
    return ans;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;ans=0;
        for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];
        int o1=0,o2=0,o3=0;
        for(int i=1;i<=n;i++){
            if(a[i]>=max(b[i],c[i]))o1++;
            else if(b[i]>=max(a[i],c[i]))o2++;
            else o3++;
            ans+=max(a[i],max(b[i],c[i]));
        }
        if(o1<=n/2&&o2<=n/2&&o3<=n/2)cout<<ans<<"\n";
        else{
            ans=as(a,b,c);
            ans=max(ans,as(b,a,c));
            ans=max(ans,as(c,a,b));
            cout<<ans<<"\n";
        }
    }
    return 0;
}

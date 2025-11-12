#include<bits/stdc++.h>
using namespace std;
int t,n,ans;bool b,c,d;
struct club{
    int o,t,th;
}a[1000010];
vector<int>a1,t1,th1;
int main(){
    freopen("club.in","r",stdin),freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        ans=0;a1.clear(),t1.clear(),th1.clear();
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i].o>>a[i].t>>a[i].th;
        for(int i=1;i<=n;i++){
            if(a1.size()==n/2)b=1;
            if(t1.size()==n/2)c=1;
            if(th1.size()==n/2)d=1;
            if(a[i].t>a[i].o&&a[i].t>a[i].th&&!c)t1.push_back(a[i].t),ans+=a[i].t;
            if(a[i].o>a[i].t&&a[i].o>a[i].th&&!b)a1.push_back(a[i].o),ans+=a[i].o;
            if(a[i].th>a[i].t&&a[i].th>a[i].o&&!d)th1.push_back(a[i].th),ans+=a[i].th;
        }cout<<ans<<"\n";
    }
}

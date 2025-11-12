#include<bits/stdc++.h>
using namespace std;
int n,ans,t;
struct xxs{
    int a,b,c,d;
}st[100005];
priority_queue<int> q1,q2,q3;
bool b[100005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>st[i].a>>st[i].b>>st[i].c;
            if(st[i].a>st[i].b&&st[i].a>st[i].c){
                ans+=st[i].a;
                st[i].d=st[i].a-max(st[i].c,st[i].b);
                q1.push(-st[i].d);
                b[i]=1;
            }
            else if(st[i].b>st[i].c&&st[i].b>st[i].a){
                ans+=st[i].b;
                st[i].d=st[i].b-max(st[i].c,st[i].a);
                q2.push(-st[i].d);
                b[i]=1;
            }
            else if(st[i].c>st[i].b&&st[i].c>st[i].a){
                ans+=st[i].c;
                st[i].d=st[i].c-max(st[i].a,st[i].b);
                q3.push(-st[i].d);
                b[i]=1;
            }
            else{
                ans+=max({st[i].a,st[i].b,st[i].c});
            }
        }
        while(q1.size()>n/2){
            ans+=q1.top();
            q1.pop();
        }
        while(q2.size()>n/2){
            ans+=q2.top();
            q2.pop();
        }
        while(q3.size()>n/2){
            ans+=q3.top();
            q3.pop();
        }
        while(q1.size()) q1.pop();
        while(q2.size()) q2.pop();
        while(q3.size()) q3.pop();
        cout<<ans<<'\n';
        ans=0;
    }
    return 0;
}
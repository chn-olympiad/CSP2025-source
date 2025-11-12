#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],b[N],c[N];
deque<int> q1,q2,q3;
int n,t,siz[3];
bool vis[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n; for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
        int ans=0; memset(vis,0,sizeof(vis));
        q1.clear(); q2.clear(); q3.clear();
        for(int i=1;i<=n;i++){
            int cnt=0;
            if(q1.size()<=n/2){
                stack<int> st; int flag=0,f=0;
				if(q1.empty()){q1.push_back(a[i]); f=1;}
				if(!f){
                    while(!q1.empty()) if(q1.back()<a[i]){st.push(q1.back()); q1.pop_back(); flag=1;} cnt+=flag;
                    q1.push_back(a[i]);
                    while(!st.empty()) if(q1.size()<=n/2) q1.push_back(st.top()),st.pop();
				}
            }
            if(q2.size()<=n/2){
                stack<int> st; int flag=0,f=0;
				if(q2.empty()){q2.push_back(b[i]); f=1;}
				if(!f){
                    while(!q2.empty()) if(q2.back()<b[i]){st.push(q2.back()); q2.pop_back(); flag=1;} cnt+=flag;
                    q2.push_back(b[i]);
                    while(!st.empty()) if(q2.size()<=n/2) q2.push_back(st.top()),st.pop();
				}
            }
            if(q3.size()<=n/2){
                stack<int> st; int flag=0,f=0;
				if(q3.empty()){q3.push_back(c[i]); f=1;}
				if(!f){
                    while(!q3.empty()) if(q3.back()<c[i]){st.push(q3.back()); q3.pop_back(); flag=1;} cnt+=flag;
                    q3.push_back(c[i]);
                    while(!st.empty()) if(q3.size()<=n/2) q3.push_back(st.top()),st.pop();
				}
            }
            if(cnt==1) vis[i]=1;
        }
        cout<<"ok";
        siz[0]=q1.size(); siz[1]=q2.size(); siz[2]=q3.size();
        while(!q1.empty()){ans+=q1.front(); q1.pop_front();}
        while(!q2.empty()){ans+=q2.front(); q2.pop_front();}
        while(!q3.empty()){ans+=q3.front(); q3.pop_front();}
        for(int i=1;i<=n;i++){
            if(vis[i]) continue;
            int mx=-1,go=-1;
            if(mx<a[i]&&siz[0]<n/2) mx=a[i],go=0;
            if(mx<b[i]&&siz[1]<n/2) mx=b[i],go=1;
            if(mx<c[i]&&siz[2]<n/2) mx=c[i],go=2;
            ans+=mx; siz[go]++; vis[i]=1;
        }
        cout<<ans<<'\n';
    }
    return 0;
}

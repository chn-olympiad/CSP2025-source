#include<bits/stdc++.h>
// g++ -O2 -std=c++14 -static -o club club.cpp
#define pint pair<int,int>
using namespace std;
const int N=1e5+16;
int va,vb,vc;
int a[N],b[N],c[N];
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    for(cin>>T;T;T--){
        int n,ans=0;cin>>n;
        priority_queue<pint,vector<pint>,less<pint> > qa;
        priority_queue<pint,vector<pint>,less<pint> > qb;
        priority_queue<pint,vector<pint>,less<pint> > qc;
        va=vb=vc=0;
        for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];
        for(int i=1;i<=n;i++){
            int tem1,tem2,tem3;
            if(va<n/2)tem1=a[i];
            else{
                int t=qa.top().first;
                tem1=a[i]+t;
            }
            if(vb<n/2)tem2=b[i];
            else{
                int t=qb.top().first;
                tem2=b[i]+t;
            }
            if(vc<n/2)tem3=c[i];
            else{
                int t=qc.top().first;
                tem3=c[i]+t;
            }
            if(tem1==max({tem1,tem2,tem3})){
                ans+=tem1;
                if(va<n/2)va++;
                else{
                    int t=qa.top().second;
                    qa.pop();
                    if(b[t]>c[t])qb.push({max(a[i],c[i])-b[i],t});
                    else qc.push({max(b[i],a[i])-c[i],t});
                }
                qa.push({max(b[i],c[i])-a[i],i});
            }
            else if(tem2==max({tem1,tem2,tem3})){
                ans+=tem2;
                if(vb<n/2)vb++;
                else{
                    int t=qb.top().second;
                    qb.pop();
                    if(a[t]>c[t])qa.push({max(b[i],c[i])-a[i],t});
                    else qc.push({max(b[i],a[i])-c[i],t});
                }
                qb.push({max(a[i],c[i])-b[i],i});
            }
            else if(tem3==max({tem1,tem2,tem3})){
                ans+=tem3;
                if(vc<n/2)vc++;
                else{
                    int t=qc.top().second;
                    qc.pop();
                    if(b[t]>a[t])qb.push({max(a[i],c[i])-b[i],t});
                    else qa.push({max(b[i],c[i])-a[i],t});
                }
                qc.push({max(b[i],a[i])-c[i],i});
            }
            // cout<<tem1<<" "<<tem2<<" "<<tem3<<" "<<ans<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}
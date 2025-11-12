#include<bits/stdc++.h>
//#define LOCAL
using namespace std;
const int N=1e5+1,inf=1e9+1;
int a[N],b[N],c[N],n;
int dfs(int nowa,int nowb,int nowc,int i,int nowval){
    if(i==n+1)return nowval;
    int ra=0,rb=0,rc=0;
    if(nowa<n/2)ra=dfs(nowa+1,nowb,nowc,i+1,nowval+a[i]);
    if(nowb<n/2)rb=dfs(nowa,nowb+1,nowc,i+1,nowval+b[i]);
    if(nowc<n/2)rc=dfs(nowa,nowb,nowc+1,i+1,nowval+c[i]);
    return max(ra,max(rb,rc));
}
int dfs2(int nowa,int nowb,int nowc,int i,int nowval){
    if(i==n+1)return nowval;
    int ra=0,rb=0,rc=0;
    if(nowa<n/2)ra=dfs(nowa+1,nowb,nowc,i+1,nowval+a[i]);
    if(nowb<n/2)rb=dfs(nowa,nowb+1,nowc,i+1,nowval+b[i]);
    return max(ra,rb);
}
int main(){
#ifndef LOCAL
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
#endif // LOCAL
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        bool flaga=true,flagb=true;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            int now=(a[i]!=0)+(b[i]!=0)+(c[i]!=0);
            if(now>1)flaga=false;
            if(now>2)flagb=false;
        }
        if(n==2){
            cout<<max(max(max(a[1]+b[2],a[1]+b[3]),max(a[2]+b[1],a[2]+b[3])),max(a[3]+b[1],a[3]+b[2]));
        }else if(n<=15){
            int ans=dfs(0,0,0,0,0);
            cout<<ans;
        }else{
            if(flaga){
                vector<int> v;
                for(int i=1;i<=n;i++){
                    v.push_back(a[i]);
                }
                sort(a+1,a+1+n);
                int ans=0;
                for(int i=1;i<=n/2;i++){
                    ans+=a[i];
                }
                cout<<ans;
            }else if(flagb){
                int ans=dfs2(0,0,0,0,0);
                cout<<ans;
            }else{
                int ans=dfs(0,0,0,0,0);
                cout<<ans;
            }
        }
        cout<<endl;
    }

    return 0;
}
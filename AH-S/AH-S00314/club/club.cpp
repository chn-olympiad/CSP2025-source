#include <iostream>
#include <queue>
using namespace std;
const int N=1e5+5;
int t,n,a[N][4],mc1[N],mc2[N],c[4],mc;
long long ans;
priority_queue<int,vector<int>,greater<int>>q;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        ans=0;
        mc=0;
        for(int i=1;i<=3;i++)c[i]=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            mc1[i]=0;mc2[i]=0;
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
                if(a[i][j]>a[i][mc1[i]]){
                    mc1[i]=j;
                }
            }
            for(int k=1;k<=3;k++){
                if(a[i][k]>a[i][mc2[i]]&&a[i][k]<a[i][mc1[i]]){
                    mc2[i]=k;
                }
            }
            c[mc1[i]]++;
        }
        for(int i=1;i<=3;i++){
            if(c[i]>c[mc])mc=i;
        }
        for(int i=1;i<=n;i++){
            ans+=a[i][mc1[i]];
        }
        if(c[mc]<=(n>>1))cout<<ans<<'\n';
        else{
            while(!q.empty())q.pop();
            int cc=c[mc]-(n>>1);
            for(int i=1;i<=n;i++){
                if(mc1[i]==mc){
                    q.push(a[i][mc]-a[i][mc2[i]]);
                }
            }
            while(cc--){
                ans-=q.top();
                q.pop();
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}

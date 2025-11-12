#include<bits/stdc++.h>
using namespace std;
int t,n;
struct node{
    int numm,id;
};
bool vis[100010];
int maxx[100010],k;
long long ans=0;
node a[100010],b[100010],c[100010];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        ans=0;
        for(int i=0;i<n;i++){
            cin>>a[i].numm>>b[i].numm>>c[i].numm;
            maxx[i]=max(a[i].numm,max(b[i].numm,c[i].numm));
            ans+=maxx[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=10+10;
int mp[N][N];
struct node{
    int id,s;
}e[N*N];
inline bool cmp(node a,node b){
    return a.s>b.s;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,it=0,ans=0,ans2=0;cin>>n>>m;
    for(int i=1;i<=n*m;++i){
        cin>>e[i].s;e[i].id=i;
    }
    stable_sort(e+1,e+n*m+1,cmp);
    for(int i=1;i<=n*m;++i){
        if(e[i].id==1){
            it=i;break;
        }
    }
    ans=ceil(it*1.0/m);
    if(ans%2==0){
        ans2=n-(it-((ans-1)*n))+1;
    }
    else{
        ans2=it-((ans-1)*n);
    }
    cout<<ans<<" "<<ans2<<endl;
    return 0;
}

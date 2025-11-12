#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct club_love{
    int a1,a2,a3;
};
int t,n;
long long ans=0;
club_love love[N];
bool cmp(club_love x,club_love y){
    return x.a1>y.a1;
}
void dfs(int member,int club1,int club2,int club3,long long love_num){
    if(member>n){
        ans=max(ans,love_num);
        return;
    }
    if(club1<n/2){
        dfs(member+1,club1+1,club2,club3,love_num+love[member].a1);
    }
    if(club2<n/2){
        dfs(member+1,club1,club2+1,club3,love_num+love[member].a2);
    }
    if(club3<n/2){
        dfs(member+1,club1,club2,club3+1,love_num+love[member].a3);
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        ans=0;
        memset(love,0,sizeof(love));
        bool l0_a2_a3=true;
        bool l0_a3=true;
        for(int j=1;j<=n;j++){
            cin>>love[j].a1>>love[j].a2>>love[j].a3;
            if(love[j].a2>0||love[j].a3>0)l0_a2_a3=false;
            if(love[j].a3>0)l0_a3=false;
        }
        if(l0_a2_a3){
            sort(love+1,love+n+1,cmp);
            for(int j=1;j<=n/2;j++){
                ans+=love[j].a1;
            }
            cout<<ans<<"\n";
            continue;
        }
        //else if(l0_a3){
        //
        //}
        dfs(1,0,0,0,0);
        cout<<ans<<"\n";
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N][4],ans=INT_MIN,n,club1,club2,club3;
bool check(){
    if(club1<=n/2 && club2<=n/2 && club3<=n/2)
        return true;
    else return false;
}
void dfs(int i,int cnt){
    if(i>n){
        if(check()){
            ans=max(ans,cnt);
        }
        return ;
    }
    club1++;
    dfs(i+1,cnt+a[i][1]);
    club1--;

    club2++;
    dfs(i+1,cnt+a[i][2]);
    club2--;

    club3++;
    dfs(i+1,cnt+a[i][3]);
    club3--;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        ans=INT_MIN;
        club1=club2=club3=0;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        dfs(1,0);
        cout<<ans<<endl;
    }
    return 0;
}

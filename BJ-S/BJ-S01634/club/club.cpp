#include<bits/stdc++.h>
using namespace std;
int t,n,hw[3],ans;
struct man{
    int x[4];
    int want;
}a[100005];
bool cmp(man A,man B){
    return min(A.x[A.want]-A.x[(A.want+1)%3],A.x[A.want]-A.x[(A.want+2)%3])<min(B.x[B.want]-B.x[(B.want+1)%3],B.x[B.want]-B.x[(B.want+2)%3]);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        int cnt;
        for(int i=1;i<=n;i++){
            cin>>a[i].x[0]>>a[i].x[1]>>a[i].x[2];
            cnt=max({a[i].x[0],a[i].x[1],a[i].x[2]});
            for(int j=0;j<3;j++){
                if(a[i].x[j]==cnt)a[i].want=j;
            }
        }
        sort(a+1,a+n+1,cmp);
        memset(hw,0,sizeof(hw));
        for(int i=1;i<=n;i++){
            hw[a[i].want]++;
        }
        if(hw[0]>(n/2)){
            for(int i=1;i<=(hw[0]-(n/2));i++){
                if(a[i].want!=0)continue;
                if((a[i].x[0]-a[i].x[1])<(a[i].x[0]-a[i].x[2]))a[i].want=1;
                else a[i].want=2;
            }
        }
        if(hw[1]>(n/2)){
            for(int i=1;i<=(hw[1]-(n/2));i++){
                if(a[i].want!=1)continue;
                if((a[i].x[1]-a[i].x[0])<(a[i].x[1]-a[i].x[2]))a[i].want=0;
                else a[i].want=2;
            }
        }
        if(hw[2]>(n/2)){
            for(int i=1;i<=(hw[0]-(n/2));i++){
                if(a[i].want!=2)continue;
                if((a[i].x[2]-a[i].x[0])<(a[i].x[2]-a[i].x[1]))a[i].want=0;
                else a[i].want=1;
            }
        }
        for(int i=1;i<=n;i++){
            ans+=a[i].x[a[i].want];
        }
        cout<<ans<<endl;
        ans=0;
    }
    return 0;
}

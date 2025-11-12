#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("club.in","r",stdin);
   freopen("club.out","w",stdout);
   int testnum;
   cin>>testnum;
   for(int testnumi=1;testnumi<=testnum;testnumi++){
        int n;
        cin>>n;
        int a[100001][5];
        int p[100001][5];
        int lk[5][5];
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        for(int i=1;i<=n;i++){
            p[i][1]=max({a[i][1],a[i][2],a[i][3]});
            p[i][2]=min({max({a[i][1],a[i][2]}),max({a[i][2],a[i][3]}),max({a[i][3],a[i][1]})});
            p[i][3]=min({a[i][1],a[i][2],a[i][3]});
            for(int j=1;j<=3;j++){
                if(a[i][j]==p[i][1])lk[1][j]++;
                if(a[i][j]==p[i][2])lk[2][j]++;
                if(a[i][j]==p[i][3])lk[3][j]++;
            }
        }
        if((lk[1][1]<=n/2)&&(lk[1][2]<=n/2)&&(lk[1][3]<=n/2)){
            int ans=0;
            for(int i=1;i<=n;i++)ans+=p[i][1];
            cout<<ans;
        }
        else{
        int ful;
        for(int i=1;i<=3;i++)if(lk[1][i]>n/2)ful=i;
        int lv [100001];
        for(int i=1;i<=n;i++){
            if(a[i][ful]==p[i][1])lv[i]=p[i][1]-p[i][2];
            else lv[i]=100001;
        }
        sort(lv+1,lv+n+1);
        int ans=0;
        for(int i=1;i<=n;i++)ans+=p[i][1];
        for(int i=1;i<=lk[1][ful]-n/2;i++){
            ans-=lv[i];
        }
        cout<<ans;
        }
   }
}

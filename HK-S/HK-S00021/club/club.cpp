#include<bits/stdc++.h>
using namespace std;
const int N=1<<17;
int t,n;
int a[N][3];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) for(int j=0;j<3;j++) scanf("%d",&a[i][j]);
        int cnt[3]={};
        for(int i=1;i<=n;i++) for(int j=0;j<3;j++) if(a[i][j]==max({a[i][0],a[i][1],a[i][2]})){
            cnt[j]++;
            break;
        }
        int sum=0;
        for(int i=1;i<=n;i++) sum+=max({a[i][0],a[i][1],a[i][2]});
        if(cnt[0]<=n/2&&cnt[1]<=n/2&&cnt[2]<=n/2){
            printf("%d\n",sum);
        }else{
            int x;
            if(cnt[0]>n/2) x=0;
            else if(cnt[1]>n/2) x=1;
            else x=2;
            for(int i=1;i<=n;i++) swap(a[i][x],a[i][0]);
            vector<int> v;
            for(int i=1;i<=n;i++) if(a[i][0]==max({a[i][0],a[i][1],a[i][2]})) v.push_back(a[i][0]-max(a[i][1],a[i][2]));
            sort(v.begin(),v.end());
            for(int i=0;i<cnt[x]-n/2;i++) sum-=v[i];
            printf("%d\n",sum);
        }
    }
    return 0;
}

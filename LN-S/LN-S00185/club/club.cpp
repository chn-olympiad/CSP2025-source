#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int t,n,ans,g;
int a[N][5];
vector<int>v[5],del;
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        for(int i=1;i<=n;i++){
            scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
            int r1=0;
            // int r1=1,r2=2,r3=3;
            // if(a[i][r1]<a[i][r2])  swap(r1,r2);
            // if(a[i][r1]<a[i][r3])  swap(r1,r3);
            if(a[i][1]>=max(a[i][2],a[i][3]))  r1=1;
            if(a[i][2]>=max(a[i][1],a[i][3]))  r1=2;
            if(a[i][3]>=max(a[i][1],a[i][2]))  r1=3;
            v[r1].push_back(i);
            ans+=a[i][r1];
        }
        int len1=v[1].size(),len2=v[2].size(),len3=v[3].size();
        if(len1>=max(len2,len3))  g=1;
        if(len2>=max(len1,len3))  g=2;
        if(len3>=max(len1,len2))  g=3;
        // printf("g= %lld\n",g);
        int len=v[g].size();
        if(len>n/2){
            int r1,r2;
            if(g==1)  r1=2,r2=3;
            if(g==2)  r1=1,r2=3;
            if(g==3)  r1=1,r2=2;
            for(int i:v[g]){
                del.push_back(a[i][g]-max(a[i][r1],a[i][r2]));
            }
            sort(del.begin(),del.end());
            for(int i=0;i<len-n/2;i++){
                ans-=del[i];
                // printf("del %lld",del[i]);
            }
        }
        printf("%lld\n",ans);
        ans=0;
        del.clear();
        for(int i=1;i<=3;i++)  v[i].clear();
        g=0;
    }
    return 0;
}
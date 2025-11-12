#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int cu[4];
int v[N][4];
int ma[N];//zuida
int wz[N];
int n,m;
int ans;
int bo(int x,int y){
    for (int i = 1;i<=y;i++){
        if (cu[i]>x/2){
            return 1;
        }
    }
    return 0;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&n);
    while(cin >> m){
            ans = 0;
     for(int i =1;i<=m;i++){
            int flag = 0;
            for(int j = 1;j<=n;j++){
                int x;
                scanf("%d",&x);
                v[i][j] = x;
                flag = max(flag,x);
            }
            ma[i] = flag;
     }
         for(int i = 1;i<=m;i++){
            ans += ma[i];
         }
       printf("%d\n",ans);
}
return 0;
}

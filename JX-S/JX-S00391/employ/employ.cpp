#include <bits/stdc++.h>
using namespace std;
char a[100050];
int n,m,sum=1;
int naix[100050];
void dfs(int x){
    if(x>0){
   sum=x*sum;
   dfs(x--);
   }
   return;

}
int main()
{
   freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
     cin>>n>>m;
     cin>>a;
     for(int i=1;i<=n;i++){
       cin>>naix[i];
     }
     int o=strlen(a);
     sum=1;
     dfs(o);
     cout<<sum;
    return 0;
}



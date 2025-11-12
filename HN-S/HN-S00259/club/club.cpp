#include<bits/stdc++.h>
using namespace std;
int a[100010][4],b[10010];
int main(){
   freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    int n,m=0,s=0,k;
    cin>>t;
    for(int w=1;w<=t;w++){
        cin>>n;
        for(int i=1;i<=n;i++){
           for(int j=1;j<=3;j++){
            cin>>a[i][j];
            m=max(m,a[i][j]);
           }
           s+=m;
        }
      b[w]=s;
    }
   for(int i=1;i<=n;i++){
    cout<<b[i];
   }
   fclose(stdin);
    fclose(stdout);
    return 0;
}

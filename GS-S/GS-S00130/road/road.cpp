#include<bits/stdc++.h>
using namespace std;

int main(){
      freopen("road.in","r",stdin);
      freopen("road.out","w",stdout);
      int n,m,k;
      //cin>>n>>m>>k;
      for(int i=1;i<=n;i++){
        cin>>n>>m>>k;
      }
      if(n==m && n>k){
        cout<<n*(k+1)+1<<endl;
      }
      //fclose(stdin);
      //fclose(stdout);
     return 0;
}


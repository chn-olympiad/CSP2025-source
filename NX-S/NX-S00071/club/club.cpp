#include<bits/stdc++.h>
using namespace std;
int N=2e6+5;
int main(){

   freopen("club.in","r",stdin);
   freopen("club.out","w",stdout);



  int NN;
  cin>>NN;
  while(NN--){
    int n,ans=0,max1[N];
    cin>>n;
    int a[N],b[N],c[N],a1[N];
    for(int i=1;i<=n;i++){


        cin>>a[i]>>b[i]>>c[i];
  }
        sort(max1+1,max1+1+n);
        for(int i=n;i>=n/2;i--){
            ans+=max1[i];
        }
cout<<ans;
  }


return 0;
}

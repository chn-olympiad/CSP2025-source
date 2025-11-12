#include<bits/stdc++.h>
using namespace std;
int T,n,a[100005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
      //  for(int i=1;i<=3;i++) dp[i][0]=0;
      memset(a,0,sizeof(a));
        cin>>n;
        for(int i=1;i<=n;i++){
            int x,y,z;
            cin>>x>>y>>z;
            a[i]=y;
        }
        sort(a+1,a+n+1);
        long long sum=0;
        for(int j=floor(n/2)+1;j<=n;j++){
            sum+=a[j];
        }
        cout<<sum<<endl;
    }
    return 0;
}

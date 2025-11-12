#include<bits/stdc++.h>
using namespace std;
int main()
{
   freopen("club.in","r",stdin);
   freopen("club.out","w",stdout);
   int t,n[10],a[100005][4],ans[10];
   cin>>t;
   for(int i=0;i<t;i++){
       cin>>n[i];
       for(int j=0;j<n[i];j++){
            for(int k=1;k<=3;k++){
               cin>>a[j][k];
       }
    }
}
    for(int i=0;i<t;i++){
       int maxx[n[i]+1],cnt[4]={0,0,0,0},s=0;
       for(int j=0;j<n[i];j++){
            for(int k=1;k<=3;k++){
                maxx[j]=max(a[j][1],max(a[j][2],a[j][3]));
                if(maxx[j]==a[j][k]){
                    cnt[k]++;
                    s+=maxx[j];
                }
       }
    }
       if(cnt[1]<=n[i]/2&&cnt[2]<=n[i]/2&&cnt[3]<=n[i]/2)
            ans[i]=s;
       else
          break;
    }
    for(int i=0;i<t;i++){
        cout<<ans[i]<<endl;
    }
return 0;
}


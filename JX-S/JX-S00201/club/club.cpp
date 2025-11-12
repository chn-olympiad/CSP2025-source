#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n;
int a[N][5];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        int ans=0,ans1=0,ans2=0,ans3=0;
        int cnt[5];
        for(int i=1;i<=3;i++)cnt[i]=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++)cin>>a[i][j];
        }
        //for(int i=1;i<=n;i++){
         //   for(int j=1;j<=3;j++){
          //      for(int k=1;k<=3;k++){
         //           if(a[i][j]>a[i][k])swap(a[i][j],a[i][k]);
          //      }
         //   }
        //}
        //for(int i=1;i<=n;i++){
         //   for(int j=1;j<=n;j++){
        //        for(int k=1;k<=3;k++){
        //            if(a[i][k]>a[j][k])swap(a[i][k],a[j][k]);
        //        }
         //   }
        //}
        //(int i=1;i<=n;i++){
         //   for(int j=1;j<=3;j++)cout<<a[i][j]<<" ";
        //    cout<<"\n";
        //}
        for(int i=1;i<=n;i++){
            int maxx=-1,id=0;
            for(int j=1;j<=3;j++){
                if(maxx<a[i][j]&&cnt[j]+1<=n/2){
                    maxx=a[i][j];
                    id=j;
                }
            }
            ans+=maxx;
            cnt[id]++;
        }
        for(int i=1;i<=3;i++)cnt[i]=0;
           for(int i=n;i>=1;i--){
                int maxx=-1,id=0;
            for(int j=1;j<=3;j++){
                if(maxx<a[i][j]&&cnt[j]+1<=n/2){
                    maxx=a[i][j];
                    id=j;
                }
            }
            ans1+=maxx;
            cnt[id]++;
        }
        for(int i=1;i<=3;i++)cnt[i]=0;
           for(int i=n;i>=1;i--){
                int maxx=-1,id=0;
            for(int j=3;j>=1;j--){
                if(maxx<a[i][j]&&cnt[j]+1<=n/2){
                    maxx=a[i][j];
                    id=j;
                }
            }
            ans2+=maxx;
            cnt[id]++;
        }
        for(int i=1;i<=3;i++)cnt[i]=0;
           for(int i=n/2;i<=n;i++){
                int maxx=-1,id=0;
            for(int j=3;j>=1;j--){
                if(maxx<a[i][j]&&cnt[j]+1<=n/2){
                    maxx=a[i][j];
                    id=j;
                }
            }
            ans3+=maxx;
            cnt[id]++;
        }
        for(int i=n/2-1;i>=1;i--){
                int maxx=-1,id=0;
            for(int j=3;j>=1;j--){
                if(maxx<a[i][j]&&cnt[j]+1<=n/2){
                    maxx=a[i][j];
                    id=j;
                }
            }
            ans3+=maxx;
            cnt[id]++;
        }
        //cout<<ans<<"-----"<<ans1<<"-----"<<ans2<<"-----"<<ans3<<"-----\n";
        cout<<max(ans1,max(ans,max(ans2,ans3)))<<"\n";
    }
    return 0;
}


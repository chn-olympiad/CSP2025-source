//45min写完55pts的dp发现简单贪心能得100pts
//i m so ppl
//i even can't cut orange problem lol
//finished at 15.40
//meow :(
//what can i say
//closed at 15.47
#include<bits/stdc++.h>
using namespace std;
int n,a[100100][3],T,snum[3],sfav[3],fav[100100],f,b[100100],cnt;
int d[100100],ans;
bool cmp(int x,int y){
    return x>y;
}
int  main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        int nn=n/2;
        for(int i=1;i<=n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];

            if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
                fav[i]=0;sfav[0]+=a[i][0];snum[0]++;
                d[i]=a[i][0]-max(a[i][1],a[i][2]);

            }
            else if(a[i][1]>=a[i][2]){
                fav[i]=1;sfav[1]+=a[i][1];snum[1]++;
                d[i]=a[i][1]-max(a[i][0],a[i][2]);
            }
            else {
                fav[i]=2;sfav[2]+=a[i][2];snum[2]++;
                d[i]=a[i][2]-max(a[i][1],a[i][0]);
            }
      //  cout<<d[i]<<endl;

        }//init


        if(snum[0]<=nn&&snum[1]<=nn&&snum[2]<=nn){//te pan
            cout<<sfav[0]+sfav[1]+sfav[2]<<endl;
            memset(snum,0,sizeof(snum));
            memset(sfav,0,sizeof(sfav));
            memset(fav,0,sizeof(fav));
            memset(b,0,sizeof(b));
            memset(d,0,sizeof(d));
            cnt=0;f=0;ans=0;
            continue;
        }

        if(snum[0]>snum[1]&&snum[0]>snum[2])f=0;//find overmem team
        else if(snum[1]>snum[2])f=1;
        else f=2;

        for(int i=1;i<=n;i++){//get ovmem chazhi
            if(fav[i]==f)b[++cnt]=d[i];
        }

        sort(b+1,b+cnt+1);
        for(int i=1;i<=snum[f]-nn;i++){
            ans+=b[i];//cout<<ans<<' ';
        }

        cout<<sfav[0]+sfav[1]+sfav[2]-ans<<endl;
        /*for(int i=0;i<=nn;i++){//sum of fav mem
            for(int j=1;j<=cnt;j++){//stu in overmem group(ya suo)
                int ii=j%2;
                if(i==0)dp[ii][i]=dp[ii^1][i]+a[b[j]][1];
                else dp[ii][i]=max(dp[ii^1][i-1]+a[b[j]][0],dp[ii^1][i]+a[b[j]][1]);
            }
        }
        cout<<dp[cnt%2][nn]<<endl;*/
        //memset(dp,0,sizeof(dp));
        //i wrote shit here TAT
        memset(snum,0,sizeof(snum));
        memset(sfav,0,sizeof(sfav));
        memset(fav,0,sizeof(fav));
        memset(b,0,sizeof(b));
        memset(d,0,sizeof(d));
        cnt=0;f=0;ans=0;
    }
    return 0;
}
//meow :)

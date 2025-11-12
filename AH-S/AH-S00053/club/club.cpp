#include<bits/stdc++.h>
using namespace std;
struct ss{
    long long c1;
    long long c2;
    long long minn=1000000000000001;
}b[100005];
struct sss{
    long long c1,c2,c3;
}a[100005],ans[5][100001];
bool cmp(ss a,ss b){
    return a.minn>b.minn;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long T;
    cin>>T;
    while(T--){
       long long n;
        cin>>n;
         long long sum=0;
         long long cnt[5];
         memset(cnt,0,sizeof(cnt));
         memset(ans,0,sizeof(ans));
         memset(a,0,sizeof(a));
         memset(b,0,sizeof(b));
        for(long long i=1;i<=n;i++){
            cin>>a[i].c1>>a[i].c2>>a[i].c3;
//          cout<<endl;
            if(a[i].c1>a[i].c2&&a[i].c1>a[i].c3){
                cnt[1]+=1;
                ans[1][cnt[1]]=a[i];
                sum+=a[i].c1;
            }
            if(a[i].c2>a[i].c1&&a[i].c2>a[i].c3){
                cnt[2]+=1;
                ans[2][cnt[2]]=a[i];
                sum+=a[i].c2;
            }
            if(a[i].c3>a[i].c1&&a[i].c3>a[i].c2){
                cnt[3]+=1;
                ans[3][cnt[3]]=a[i];
                sum+=a[i].c3;
            }

//              ans[id][cnt[id]]=a[i][id];

        }
//              cout<<1;
//________________________________________________________________________
                if(cnt[1]>n/2){

                    for(long long i=1;i<=cnt[1];i++){
                        b[i].c1=ans[1][i].c1-ans[1][i].c2;
                        b[i].c2=ans[1][i].c1-ans[1][i].c3;
                        b[i].minn=min(b[i].c1,b[i].c2);
                    }
                    sort(b+1,b+1+cnt[1],cmp);
/*
                    for(int i=1;i<=cnt[1];i++){
                        cout<<b[i].minn<<" ";
                         if(i%10==0)cout<<endl;

                    }
                    cout<<endl<<endl;
*/

                    for(long long i=cnt[1];i>n/2;i--){
//                      cout<<sum<<" "<<b[i].minn<<endl;
                        sum-=b[i].minn;
                    }
                }
                if(cnt[2]>n/2){
                    for(long long i=1;i<=cnt[2];i++){
                        b[i].c1=ans[2][i].c2-ans[2][i].c1;
                        b[i].c2=ans[2][i].c2-ans[2][i].c3;
                        b[i].minn=min(b[i].c1,b[i].c2);
                    }
                    sort(b+1,b+1+cnt[2],cmp);
/*

                    for(int i=1;i<=cnt[2];i++)cout<<b[i].minn<<" ";
                    cout<<endl<<endl;

*/
                    for(long long i=cnt[2];i>n/2;i--){
//                      cout<<sum<<" "<<b[i].minn<<endl;
                        sum-=b[i].minn;
                      }
                }
                if(cnt[3]>n/2){
                    for(long long i=1;i<=cnt[3];i++){
                        b[i].c1=ans[3][i].c3-ans[3][i].c1;
                        b[i].c2=ans[3][i].c3-ans[3][i].c2;
                        b[i].minn=min(b[i].c1,b[i].c2);
                    }
                    sort(b+1,b+1+cnt[3],cmp);

/*
                    for(int i=1;i<=cnt[3];i++)cout<<b[i].minn<<" ";
                    cout<<endl<<endl;
*/

                    for(long long i=cnt[3];i>n/2;i--){
//                      cout<<sum<<" "<<b[i].minn<<endl;
                        sum-=b[i].minn;
                    }
                }
//________________________________________________________________________-

        cout<<sum<<endl;
    }
    return 0;
}


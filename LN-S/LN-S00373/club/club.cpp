//Ren5Jie4Di4Ling5%
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    while(t--){
        int n,ans=0;
        cin>>n;
        int a[n+1][4]={};
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        vector<vector<int>> bumenren(4);
        int bumenrenshu[4]={};
        for(int i=1;i<=n;i++){
            if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
                bumenren[1].push_back(i);
                bumenrenshu[1]++;
                ans+=a[i][1];
            }
            else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
                bumenren[2].push_back(i);
                bumenrenshu[2]++;
                ans+=a[i][2];
            }
            else{
                bumenren[3].push_back(i);
                bumenrenshu[3]++;
                ans+=a[i][3];
            }
        }
        while(!(bumenrenshu[1]<=n/2&&bumenrenshu[2]<=n/2&&bumenrenshu[3]<=n/2)){
            if(bumenrenshu[1]>n/2){
                int maxbumen=0,maxren=0,minsunshi=99999999;
                for(int i=0;i<=bumenrenshu[1]-1;i++){
                    if(a[bumenren[1][i]][1]-a[bumenren[1][i]][2]<minsunshi&&bumenrenshu[2]<n/2){
                        minsunshi=a[bumenren[1][i]][1]-a[bumenren[1][i]][2];
                        maxren=i;
                        maxbumen=2;
                    }
                    if(a[bumenren[1][i]][1]-a[bumenren[1][i]][3]<minsunshi&&bumenrenshu[3]<n/2){
                        minsunshi=a[bumenren[1][i]][1]-a[bumenren[1][i]][3];
                        maxren=i;
                        maxbumen=3;
                    }
                }
                bumenren[1][maxren]=bumenren[1][bumenrenshu[1]-1];
                bumenrenshu[1]--;
                bumenrenshu[maxbumen]++;
                bumenren[maxbumen].push_back(maxren);
                ans-=minsunshi;
            }
            if(bumenrenshu[2]>n/2){
                int maxbumen=0,maxren=0,minsunshi=9999999;
                for(int i=0;i<=bumenrenshu[2]-1;i++){
                    if(a[bumenren[2][i]][2]-a[bumenren[2][i]][1]<minsunshi&&bumenrenshu[1]<n/2){
                        minsunshi=a[bumenren[2][i]][2]-a[bumenren[2][i]][1];
                        maxren=i;
                        maxbumen=1;
                    }
                    if(a[bumenren[2][i]][2]-a[bumenren[2][i]][3]<minsunshi&&bumenrenshu[3]<n/2){
                        minsunshi=a[bumenren[2][i]][2]-a[bumenren[2][i]][3];
                        maxren=i;
                        maxbumen=3;
                    }
                }
                bumenren[2][maxren]=bumenren[2][bumenrenshu[2]-1];
                bumenrenshu[2]--;
                bumenrenshu[maxbumen]++;
                bumenren[maxbumen].push_back(maxren);
                ans-=minsunshi;
            }
            if(bumenrenshu[3]>n/2){
                int maxbumen=0,maxren=0,minsunshi=9999999;
                for(int i=0;i<=bumenrenshu[3]-1;i++){
                    if(a[bumenren[3][i]][3]-a[bumenren[3][i]][1]<minsunshi&&bumenrenshu[1]<n/2){
                        minsunshi=a[bumenren[3][i]][3]-a[bumenren[3][i]][1];
                        maxren=i;
                        maxbumen=1;
                    }
                    if(a[bumenren[3][i]][3]-a[bumenren[3][i]][2]<minsunshi&&bumenrenshu[2]<n/2){
                        minsunshi=a[bumenren[3][i]][3]-a[bumenren[3][i]][2];
                        maxren=i;
                        maxbumen=2;
                    }
                }
                bumenren[3][maxren]=bumenren[3][bumenrenshu[3]-1];
                bumenrenshu[3]--;
                bumenrenshu[maxbumen]++;
                bumenren[maxbumen].push_back(maxren);
                ans-=minsunshi;
            }
        }
        cout<<endl<<ans;
    }

    return 0;
}

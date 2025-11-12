#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int a;
int b;
int chaozai;
int vis[100010][3];
int dp[100010][6];

bool Bi(int a,int i,int j){
    if (j==0){
        return 1;
    }
    else if (j==1){
        if (a+vis[i][j]>dp[i][0]){
            return 1;
        }else{
            return 0;
        }
    }else if (j==2){
        if (a+vis[i][j]>max(dp[i][0],dp[i][1])){
            return 1;
        }else{
            return 0;
        }
    }
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>a;
    while(a--){
        memset(dp,0,sizeof(dp));
        cin>>b;
        for (int i=1;i<=b;i++){
            cin>>vis[i][0]>>vis[i][1]>>vis[i][2];
        }

        chaozai = b/2;
        for (int i=1;i<=b;i++){
            for (int j=0;j<3;j++){
                int k = max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
 //               cout<<dp[i-1][j+3]<<" "<<chaozai<<endl;
                if (dp[i-1][j+3]>=chaozai){
                    //YiDian
                    if (j==0){
                        k = 0;
                    }else if(j==1){
                        k = dp[i-1][0];
                    }else{
                        k = max(dp[i-1][0],dp[i-1][1]);
                    }
                }
                if (dp[i-1][0]==k){
                    if (Bi(k,i,j)){
                        dp[i][j] = k+vis[i][j];
                        for(int m=3;m<=5;m++){
                            dp[i][m] = dp[i-1][m];
                        }
                        dp[i][j+3]++;
                    }else{
                        if(j==1){
                            if (dp[i][j-1]>vis[i][j]+dp[i-2][2]+max(vis[i-1][j-1],0)||dp[i][j+3]>=chaozai){
                                dp[i][j] = dp[i][j-1];
                            }else{
                                dp[i][j] = vis[i][j]+dp[i-2][2]+max(vis[i-1][j-1],0);
                                dp[i][j+3]++;
                            }

                        }else if(j==2){
                            if (max(dp[i][j-1],dp[i][j-2])>vis[i][j]+dp[i-2][2]+max(vis[i-1][j-1],vis[i-1][j-2])||dp[i][j+3]>=chaozai){
                                dp[i][j] = max(dp[i][j-1],dp[i][j-2]);
                            }else{
                                dp[i][j] = vis[i][j]+dp[i-2][2]+max(vis[i-1][j-1],vis[i-1][j-2]);
                            }

                        }
                    }
                }else if(dp[i-1][1]==k){
                    if (Bi(k,i,j)){
                        dp[i][j] = k+vis[i][j];
                        for(int m=3;m<=5;m++){
                            dp[i][m] = dp[i-1][m];
                        }
                        dp[i][j+3]++;
                    }else{
                        if(j==1){
                            if (dp[i][j-1]>vis[i][j]+dp[i-2][2]+max(vis[i-1][j-1],0)||dp[i][j+3]>=chaozai){
                                dp[i][j] = dp[i][j-1];
                            }else{
                                dp[i][j] = vis[i][j]+dp[i-2][2]+max(vis[i-1][j-1],0);
                                dp[i][j+3]++;
                            }

                        }else if(j==2){
                            if (max(dp[i][j-1],dp[i][j-2])>vis[i][j]+dp[i-2][2]+max(vis[i-1][j-1],vis[i-1][j-2])||dp[i][j+3]>=chaozai){
                                dp[i][j] = max(dp[i][j-1],dp[i][j-2]);
                            }else{
                                dp[i][j] = vis[i][j]+dp[i-2][2]+max(vis[i-1][j-1],vis[i-1][j-2]);
                            }

                        }
                    }
                }else if (dp[i-1][2]==k){
                    if (Bi(k,i,j)){
                        dp[i][j] = k+vis[i][j];
                        for(int m=3;m<=5;m++){
                            dp[i][m] = dp[i-1][m];
                        }
                        dp[i][j+3]++;
                    }else{
                        if(j==1){
                            if (dp[i][j-1]>vis[i][j]+dp[i-2][2]+max(vis[i-1][j-1],0)||dp[i][j+3]>=chaozai){
                                dp[i][j] = dp[i][j-1];
                            }else{
                                dp[i][j] = vis[i][j]+dp[i-2][2]+max(vis[i-1][j-1],0);
                                dp[i][j+3]++;
                            }

                        }else if(j==2){
                            if (max(dp[i][j-1],dp[i][j-2]+dp[i-2][2]+max(vis[i-1][j-1],vis[i-1][j-2]))>vis[i][j]||dp[i][j+3]>=chaozai){
                                dp[i][j] = max(dp[i][j-1],dp[i][j-2]);
                            }else{
                                dp[i][j] = vis[i][j]+dp[i-2][2]+max(vis[i-1][j-1],vis[i-1][j-2]);
                            }

                        }
                    }
                }else{
                    int l=0;
                    for (int o=3;o<=5;o++){
                        if (vis[i-1][o]>=chaozai) l=o;
                    }
                    if (l==3) dp[i][j] = vis[i][j]+dp[i-2][3]+max(vis[i-1][1],vis[i-1][2]);
                    else if (l==4) dp[i][j] = vis[i][j]+dp[i-2][3]+max(vis[i-1][0],vis[i-1][2]);
                    else if (l==5) dp[i][j] = vis[i][j]+dp[i-2][3]+max(vis[i-1][0],vis[i-1][1]);
//                    cout<<l<<" "<<"THis is cool"<<endl;
                    for(int m=3;m<=5;m++){
                        dp[i][m] = dp[i-2][m];
                    }
                    dp[i][l]++;
                    dp[i][j+3]++;
                }
            }
        }
 /*       for (int i=1;i<=b;i++){
            for (int j=0;j<6;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }*/

        cout<<dp[b][2]<<endl;
    }


    return 0;

}

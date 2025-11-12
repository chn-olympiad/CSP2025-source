#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    while(t--){
        int dp[N][5],f[N][5],maxn[N],sec[N],cnt[5]={0},tans=0;
        bool b[N][4]={false};
        int n;
        cin >> n;
        for(int j=1;j<=3;j++){
            dp[0][j]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin >> f[i][j];
            }

            if(f[i][1]>=f[i][2]){
                if(f[i][2]>=f[i][3]){
                    cnt[1]++;b[i][1]=true;
                }
                else if(f[i][2]<f[i][3]){
                    if(f[i][1]>=f[i][3]){
                        cnt[1]++;b[i][1]=true;
                    }
                    else cnt[3]++;b[i][3]=true;
                }
            }
            else if(f[i][1]<f[i][2]){
                if(f[i][2]>=f[i][3]){
                    cnt[2]++;b[i][2]=true;
                }
                else if(f[i][2]<f[i][3]){
                    cnt[3]++;b[i][3]=true;
                }
            }
            maxn[i]=max(max(f[i][1],f[i][2]),f[i][3]);
            sec[i]=2*maxn[i]-f[i][1]-f[i][2]-f[i][3]+min(min(f[i][1],f[i][2]),f[i][3]);
        }
        for(int i=1;i<=n;i++){
            tans+=maxn[i];
        }
        int rec=0,sk=0;
        for(int j=1;j<=3;j++){
            rec=cnt[j]-n/2;
            if(rec>0){
                for(int i=1;i<=n;i++){
                    if(b[i][j]==false){
                        sec[i]=INT_MAX;
                    }
                }
                break;
            }
            if(j==3){
                 sk=1;
                 cout << tans << endl;
                 break;
            }
        }
        if(sk==1) continue;
        sort(sec+1,sec+n+1);
        for(int i=1;i<=rec;i++){
            tans-=sec[i];
        }
        cout << tans << endl;
    }
    return 0;
}
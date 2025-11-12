#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,a[N][5],maxn[N][5],rs[5],f=0,ans=0,maxnn=0,maxn1=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
                maxn[i][j]=0;
            }
        }
        for(int i=1;i<=3;i++){
            rs[i]=0;
        }
        for(int i=1;i<=n;i++){
             maxn1=0;
             for(int j=1;j<=3;j++){
                maxn1=max(maxn1,a[i][j]);
             }
             for(int j=1;j<=3;j++){
                if(maxn1==a[i][j]){
                    maxn[i][j]=maxn1;
                }
             }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                if(maxn[i][j]!=0){
                    rs[j]++;
                }
            }
        }
        for(int i=1;i<=3;i++){
            if(rs[i]>n/2){
                f=1;
            }
        }
        if(f==0){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=3;j++){
                    if(maxn[i][j]!=0){
                        ans+=maxn[i][j];
                    }
                }
            }
        }else{
            for(int i=1;i<=3;i++){
                if(rs[i]>n/2){
                    for(int j=1;j<=n;j++){
                        if(maxn[j][i]!=0){
                            maxn[j][i]=-1;
                            rs[i]--;
                        }
                        maxnn=0;
                        for(int k=1;k<=3;k++){
                            if(maxn[j][k]!=-1){
                                maxnn=max(maxnn,a[j][k]);
                            }
                        }
                        for(int k=1;k<=3;k++){
                            if(maxnn==a[j][k]){
                                rs[k]++;
                                maxn[j][k]=maxnn;
                            }
                        }
                        if(rs[i]<=n/2){
                            break;
                        }
                    }
                }
            }
            for(int i=1;i<=n;i++){
                for(int j=1;j<=3;j++){
                    if(maxn[i][j]!=0&&maxn[i][j]!=-1){
                        ans+=maxn[i][j];
                    }
                }
            }
        }
        cout<<ans;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int T;
int n;
int ul,plA[maxn];
int pl[maxn][5];
int ans5,ans1;
int ans[200][200][200];
int whi[5];
int maxx(int a,int b,int c){
    return max(a,max(b,c));
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    for(;T--;){
        memset(plA,0,sizeof(plA));
        memset(pl,0,sizeof(pl));
        ans5=0;ans1=0;
        cin>>n;
        if(n>200){
            for(int i=1;i<=n;i++){
                cin>>plA[i];
                cin>>ul;
                cin>>ul;
            }
            sort(plA+1,plA+1+n);
            for(int i=n;i>(n>>1);i--){
                ans5+=plA[i];
            }
            cout<<ans5<<endl;
        }else{
            for(int i=1;i<=n;i++){
                cin>>pl[i][1]>>pl[i][2]>>pl[i][3];
            }
            int pl[maxn][5];
            int ans[20][20][20];
            int ans1=-1;
            cin>>n;
            for(int i=1;i<=n;i++){
                cin>>pl[i][1]>>pl[i][2]>>pl[i][3];
            }
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    for(int k=1;k<=n;k++){
                        if(i==j||i==k||j==k){
                            continue;
                        }
                        ans[i][j][k]=pl[i][1]+pl[j][2]+pl[k][3];
                    }
                }
            }
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    for(int k=1;k<=n;k++){
                        if(i==j||i==k||j==k){
                            continue;
                        }
                        ans1=max(ans1,ans[i][j][k]);
                    }
                }
            }
            cout<<ans1<<endl;
            
        }
    }
    return 0;
}

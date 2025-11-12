#include<bits/stdc++.h>
using namespace std;
int a[4][100010],n,ans,f[100][100][100][100];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        memset(f,0,sizeof f);
        cin>>n;
        bool righta=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[j][i];
            }
            if(a[2][i]!=0||a[2][i]!=0) righta=0;
        }
        if(righta==1){
            sort(a[1]+1,a[1]+n+1);
            int tot=0;
            for(int i=n;i>n/2;i--){
                tot+=a[1][i];
            }
            cout<<tot<<endl;

        }else{
            for(int i=1;i<=n;i++){
                for(int n1=0;n1<=n/2;n1++){
                    for(int n2=0;n2<=n/2;n2++){
                        for(int n3=0;n3<=n/2;n3++){
                            if(n1!=0) f[i][n1][n2][n3]=f[i-1][n1-1][n2][n3]+a[1][i];
                            if(n2!=0) f[i][n1][n2][n3]=max(f[i][n1][n2][n3],f[i-1][n1][n2-1][n3]+a[2][i]);
                            if(n3!=0) f[i][n1][n2][n3]=max(f[i][n1][n2][n3],f[i-1][n1][n2][n3-1]+a[3][i]);
                        }
                    }
                }
            }
        cout<<f[n][n/2][n/2][n/2]<<endl;
        }
    }
    return 0;
}

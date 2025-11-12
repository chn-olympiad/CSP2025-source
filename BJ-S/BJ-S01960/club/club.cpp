#include<bits/stdc++.h>
using namespace std;
int n,t;

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t>0){
        cin >> n;
        int a[n+1][4]={0};
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin >> a[i][j];
            }
        }


        int x[n+1],y[4]={0},ans=0;
        bool z[4];
        for(int i=1;i<=n;i++){
            x[i]=a[i][1];
            y[1]++;
            if(a[i][2]>x[i]){
                x[i]=a[i][2];
                y[2]++;
                y[1]=0;
            }
            if(a[i][3]>x[i]){
                x[i]=a[i][3];
                y[3]++;
                y[1]=0;
            }
        }

        for (int i=1;i<=n;i++){
            ans+= x[i];
        }

        for(int i=1;i<=3;i++){
            z[i]=true;
            for(int j=1;j<=n;j++){
                if(a[j][i]!=0){
                    z[i]=false;
                }
            }
        }

        for(int i=1;i<=3;i++){
            if(z[i]==true){
                ans--;
            }
        }


        cout << ans << endl;

        t--;
    }


    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen(club.in,"r",stdin);
    freopen(club.out,"w",stdout);
    int t,n,max2;
    cin>>t;
    int s[t];
    long long a[100010][5],b[100010][5];
    while(t--){
        cin>>n;
        max2=-1;

        for (int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
            }
        }
        b[1][2]=a[1][2];
        b[1][1]=a[1][1];
        b[1][3]=a[1][3];
        s[0]=6;
        for (int i=2;i<=n;i++){
            for (int j=1; j<=3;j++){
                if (j==1){
                    b[i][j]=max(a[i][j]+b[i-1][j+1],a[i][j]+b[i-1][j+2]);

                }
                else if (j==2){
                    b[i][j]=max(a[i][j]+b[i-1][j-1],a[i][j]+b[i-1][j+1]);

                }
                else if (j==3){
                    b[i][j]=max(a[i][j]+b[i-1][j-2],a[i][j]+b[i-1][j-1]);

                }
                else if (j==-1){
                    cout<<s[0];
                }


            }for(int j=1;j<=3;j++)
            {max2=b[i][j];}
        }

        cout<<max2<<endl;
    }

    return 0;
}

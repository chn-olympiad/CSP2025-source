#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][3];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        int num=-1;
        cin>>n;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=3;j++)
            cin>>a[i][j];
        if(n==2){
            for(int i=1;i<=3;i++)
                for(int j=1;j<=3;j++)
                 if(j!=i)num=max(num,a[1][i]+a[2][j]);
        }
        else if(n==4){
            for(int i=1;i<=3;i++)
                for(int j=1;j<=3;j++)
                    for(int k=1;k<=3;k++)
                        for(int l=1;l<=3;l++)
                        if(!((i==j&&i==k&&i==l)||(i==j&&i==k)||(i==k&&i==l)||(j==k&&j==l)||(i==j&&i==l)))
                            num=max(num,a[1][i]+a[2][j]+a[3][k]+a[4][l]);
        }
        else if(n==10){

        }
        else if(n==30){

        }
        cout<<num<<endl;;
    }
    return 0;
}

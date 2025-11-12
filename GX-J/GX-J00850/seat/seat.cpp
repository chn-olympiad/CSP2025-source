# include<bits/stdc++.h>
using namespace std;
int main(){

    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);



    int m,n,a[1001],b[101][101];
    int q1,q2,q3,q4=1,q5=0;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    q2=a[1];
    for(int i=1;i<=n*m;i++){
        for(int j=i+1;j<=m*n;j++){
            if(a[i]<a[j]){
            q1=a[i];
            a[i]=a[j];
            a[j]=q1;

            }
        }
    }




    for(int i=1;i<=n*m;i++){
        if(a[i]==q2) q3=i;
    }



    int x=1,y=1;

        for(x=1;x<=m;x++){
            if(y!=n){
                for(y=1;y<=n;y++){
                    b[x][y]=q4;
                    q4++;
                }
            }else if(y==n){
                for(y=n;y>=1;y--){
                     b[x][y]=q4;
                     q4++;

                }

            }
        }


    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(b[i][j]==q3)
                cout<<i<<" "<<j;
        }
    }

    return 0;
}


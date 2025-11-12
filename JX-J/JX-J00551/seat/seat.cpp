#include<bits/stdc++.h>
using namespace std;
int a[500][500];
int b[1000];
int k=1,op;
int main(){
    freopen("seat.in","r",stdin);
   freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int p=n*m;
    for(int i=0;i<p;i++)
    {
        cin>>b[i];
    }
    op=b[0];
    for(int i=1;i<=m;i++)
        {
        if(i%2==0){
            for(int z=n;z>=1;z--)
                {

            a[z][i]=k;
             k=k+1;
            }

        }
          else{
        for(int j=1;j<=n;j++){

            a[j][i]=k;
            k=k+1;
        }
      }
    }
    int cnt=0;
    sort(b+0,b+p+0);
    for(int i=p;i>0;i--,cnt++){

        if(b[i]==op){
            break;
        }

    }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i][j]==cnt)cout<<j<<" "<<i;
            }
        }





    return 0;
}

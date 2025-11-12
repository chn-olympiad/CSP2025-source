#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int x,y,n,z[100],a[9][9],b[2];
    cin>>x;
    cin>>y;
    int r,i;
    for(i=0;i<x*y;i++){
        cin>>z[i];
    }
    r=z[0];

    for(int j=0;j<i;j++){
        for(int s=0;s<i;s++){
            if(z[s]<z[s+1]){
            swap(z[s],z[s+1]);
        }
    }
    }
cout<<z[0]<<endl;
    int c=0,f=0;
     for(int k=1;k<x+1;k++){
            if(f==0){
                for(int j=1;j<y+1;j++){
                a[k][j]=z[c];
                c++;
                if(a[k][j]==r){
                    b[1]=k;
                    b[2]=j;

                }f=1;
            }
            }else{
             for(int j=y;j>0;j--){
                a[k][j]=z[c];
                c++;
                if(a[k][j]==r){
                    b[1]=k;
                    b[2]=j;

                }f=0;
            }

        }
     }
    cout<<b[1]<<" "<<b[2];
    return 0;
}



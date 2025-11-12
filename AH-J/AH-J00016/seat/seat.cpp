#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a=0,b=0,c[9][9],d,e;
    cin>>a>>b;
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin>>c[i][j];
        }
    }
    for(int i=a;i>0;i--){
        for(int j=b;j>0;j--){
                if(j!=1&&i!=1){
                    if(c[i][j]>c[i][j-1]){
                        d=c[i][j];
                        e=c[i][j-1];
                        c[i][j]=e;
                        c[i][j-1]=d;
                    }
             }


                if(j==1&&i!=1){
                    if(c[i][j]>c[i-1][j-1]){
                        d=c[i][j];
                        e=c[i-1][j-1];
                        c[i][j]=e;

                        c[i-1][j-1]=d;
                    }
                }
                if(j==1&&i==1){

                }
                    }
                }


    for(int i=a;i>0;i++){
        for(int j=b;j>0;j++){
            cout<<c[i][j];
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    int n;
    int b;
    int i,j,k,m,q,p,e,y;
    b=0;
    cin>>t;
    int a[100][100];
    int c[100];
    for(i=0;i<t;i++){
        cin>>n;
        for(j=0;j<n;j++){
            for (k=0;k<3;k++){
                cin>>a[j][k];
            }
        }
        for(e=0;e<3;e++){
            for(j=0;j<n/2;j++){
                for(k=0;k<n;k++){
                    if (a[k][e]>=b){
                        b=a[k][e];
                        for(y=0;y<3;y++){
                            a[k][y]=0;
                        }
                    }
                }
                c[j]=b;
                b=0;
                }
            for(p=0;p<10;p++){
            m=m+c[p];
            }
        }
        cout<<m+1;
    }

    return 0;
}

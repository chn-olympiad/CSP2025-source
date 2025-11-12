#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n;
    cin>>n;
    while(n--){
        int m;
        cin>>m;
        int s[3][m];
        for(int i=0;i<m;i++){
            for(int j=0;j<3;j++){
                cin>>s[i][j];
            }
        }
        int q=0,w=0,e=0;
        int j=m/2,ja1=m/2,j1=m/2;
        while(j--){
            int me=0,m1=0;
            for(int i=0;i<m;i++){
                if(s[i][0]>me){
                    me=s[i][0];
                    m1=i;
                }
            }
            q+=me;
            s[m1][0]=0;
            s[m1][1]=0;
            s[m1][2]=0;
        }
        while(ja1--){
            int me1=0,m11=0;
            for(int i=0;i<m;i++){
                if(s[i][1]>me1){
                    me1=s[i][1];
                    m11=i;
                }
            }
            w+=me1;
            s[m11][0]=0;
            s[m11][1]=0;
            s[m11][2]=0;
        }
        while(j1--){
            int me12=0,m112=0;
            for(int i=0;i<m;i++){
                if(s[i][2]>me12){
                    me12=s[i][2];
                    m112=i;
                }
            }
            e+=me12;
            s[m112][0]=0;
            s[m112][1]=0;
            s[m112][2]=0;
        }
        cout<<e+w+q<<endl;
    }
     return 0;
}

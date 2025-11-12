#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n,max1=0,max2=0,max3=0,pf=0,total=0,pd;
    cin>>t;
    for(int i=0;i<t;i++){
            cin>>n;
            int c1[n],c2[n],c3[n];
            for(int j=0;j<n;j++){
                cin>>c1[j]>>c2[j]>>c3[j];

            }
            for(int j=0;j<n;j++){
                if(c1[j]>pf&&max1<n/2){
                    pf=c1[j];
                    pd=1;

                }
                if(c2[j]>pf&&max2<n/2){
                    pf=c2[j];
                    pd=2;

                }
                if(c3[j]>pf&&max3<n/2){
                    pf=c3[j];
                    pd=3;

                }
                if(pd==1){
                    max1+=1;
                }
                else if(pd==2){
                    max2+=1;
                }
                else if(pd==3){
                    max3+=1;
                }
                total+=pf;
            }
            cout<<total;
            total=0;
            pf=0;


    }

    return 0;

}

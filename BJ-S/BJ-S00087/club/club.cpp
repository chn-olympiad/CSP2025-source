#include<bits/stdc++.h>
using namespace std;
int t,n,myd[100009][4],rs[3],e[100009],fe;
long ans(){
    long f=0;
    for(int a=0;a<n;a++){
        f+=myd[a][myd[a][3]];
    }
    return f;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int h=0;h<t;h++){
        fe=0;
        cin>>n;
        for(int a=0;a<n;a++){
            cin>>myd[a][0]>>myd[a][1]>>myd[a][2];
            if(myd[a][0]>myd[a][1]&&myd[a][0]>myd[a][2]){
                myd[a][3]=0;
            }else if(myd[a][1]>myd[a][0]&&myd[a][1]>myd[a][2]){
                myd[a][3]=1;
            }else{
                myd[a][3]=2;
            }
            rs[myd[a][3]]++;
        }
        if(rs[0]>n/2){
            for(int a=0;a<n;a++){
                if(myd[a][3]==0){
                    e[fe]=myd[a][0]-max(myd[a][1],myd[a][2]);
                    fe++;
                }
            }
        }else if(rs[1]>n/2){
            for(int a=0;a<n;a++){
                if(myd[a][3]==1){
                    e[fe]=myd[a][1]-max(myd[a][0],myd[a][2]);
                    fe++;
                }
            }
        }else if(rs[2]>n/2){
            for(int a=0;a<n;a++){
                if(myd[a][3]==2){
                    e[fe]=myd[a][2]-max(myd[a][1],myd[a][0]);
                    fe++;
                }
            }
        }
        sort(e,e+fe);
        int m1=fe-n/2;
        long m2=ans();
        for(int a=0;a<m1;a++){
            m2-=e[a];
        }
        cout<<m2;
    }
    return 0;
}
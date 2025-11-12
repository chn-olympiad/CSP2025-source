#include<bits/stdc++.h>
using namespace std;
int n[105],a1[100005],a2[100005],a3[100005];
int d[100005],ddd[10005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >>t;
    for(int i=0;i<t;i++){ddd[i]=0;}
    for(int i=0;i<t;i++){
        cin >>n[i];
        int d11=0,d22=0,d33=0;
        int a=n[i]/2;
        for(int j=0;j<n[i];j++){
            int d111=0,d222=0,d333=0;
            cin >>a1[i]>>a2[i]>>a3[i];
            d[j]=max(a1[i],a2[i]);
            d[j]=max(d[j],a3[i]);//×î´óÖµ
            if(d[j]==a1[i]){if(d11<=a){d11++;d111+=a1[i];}}
            else if(d[j]==a2[i]){if(d22<=a){d22++;d222+=a2[i];}}
            else{if(d33<=a){d33++;d333+=a3[i];}}
            int b=d111+d222+d333;
            ddd[i]+=b;
        }
    }
    for(int i=0;i<t;i++){cout <<ddd[i]<<endl;}
    return 0;
}

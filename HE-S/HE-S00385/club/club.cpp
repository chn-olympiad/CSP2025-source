#include<bits/stdc++.h>
using namespace std;
long long a,b,c1=0,c2=0,c3=0,d=0,e1=0,e2=0,e3=0,f,g,z1[100100],z2[100100],z3[100100],zz1[100100],zz2[100100],zz3[100100];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&a);
    for(int i=1;i<=a;i++){
        scanf("%lld",&b);
        for(int j=1;j<=b;j++){
            cin>>z1[j]>>z2[j]>>z3[j];
            if(max(z1[j],max(z2[j],z3[j]))==z1[j]){
                c1++;
                zz1[c1]=z1[j]-max(z2[j],z3[j]);
                d+=z1[j];
            }
            else if(max(z1[j],max(z2[j],z3[j]))==z2[j]){
                c2++;
                zz2[c2]=z2[j]-max(z1[j],z3[j]);
                d+=z2[j];
            }
            else{
                c3++;
                zz3[c3]=z3[j]-max(z2[j],z1[j]);
                d+=z3[j];
            }
        }
        sort(zz1+1,zz1+c1+1);
        sort(zz2+1,zz2+c2+1);
        sort(zz3+1,zz3+c3+1);
        if(c1>b/2){
            for(int j=1;j<=c1-b/2;j++){
                d-=zz1[j];
            }
        }
        if(c2>b/2){
            for(int j=1;j<=c2-b/2;j++){
                d-=zz2[j];
            }
        }
        if(c3>b/2){
            for(int j=1;j<=c3-b/2;j++){
                d-=zz3[j];
            }
        }
        cout<<d<<endl;
        d=0;
        c1=0;
        c2=0;
        c3=0;
    }
    return 0;
}

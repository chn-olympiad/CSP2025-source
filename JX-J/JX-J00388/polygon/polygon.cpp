#include<bits/stdc++.h>
using namespace std;
int c,a,ac[100000],b,aac[100000],js=0,o[100000];
long acc;
long x(int y,int s){
    int u=1;
    for(int i=1;i<y;i++){
        u*=10;
    }
    return u*s;
}
long z(){
    long p=0;
    for(int i=1;i<=js;i++){
        if(aac[i]!=0){
            p+=x(ac[i],i);
        }
    }
    return p;
}
int r(){
    int y=z();
    for(int i=1;i<=js;i++){
        if(y==o[i])return 0;
    }
    return 1;
}
//void q(int r,int w){
//    cout<<r<<" ";
//    if(w==1)cout<<endl;
//    return ;
//}
int pd(long h){
    int m=0,s=0,j;
    for(int i=1;i<=c;i++){
        if(aac[i]!=0){
            m=max(m,ac[i]);
            s++;
            //q(m,0);
        }
    }
    if(s<3){
        //q(0,1);
        return 0;
    }
    if(h>m*2 && r()){
        js++;
        //q(js,1);
        return 1;
    }
    //q(0,1);
    return 0;
}
int acn(long h,int ii){
    long s=0,j=ii;
    if(ii==0)j=1;
    /*if(ii==0){
        if(pd(h)==1)
        {
            s+=acn(h,j);
        }
    }*/
    for(int i=0+ii;i<=c;i++){
        if(aac[i]!=0){
            aac[i]=0;
            if(pd(h-ac[i])==1)s+=acn(h-ac[i],j);
            aac[i]=1;
            //aac[i]=0;
            s%=998244353;
        }
        //else if(aac[i]!=0){
            //if(pd(h-ac[i])==1)s+=acn(h-ac[i],j);
            //aac[i]=0;
        //}
    }
    return s;
}

int main(){
    aac[0]=1;
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>c;
    for(int i=1;i<=c;i++){
        scanf("%d",&ac[i]);
        acc+=ac[i];
        aac[i]=1;
    }
    acn(acc,0);
    cout<<js/2;
    return 0;
}

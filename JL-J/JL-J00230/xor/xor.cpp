#include <bits/stdc++.h>
using namespace std;
int ER(int a){
    if(a==0){
        return 0;
    }
    int x=a,i=1,k=0;
    while(x>1){
        k+=(x%2)*i;
        x=x/2;
        i*=10;
    }
    k+=i;
    return k;
}
int JIA(int a,int b){
    int x=a+b,y=x,i=1;
    while(y>0){
        if(y%10==2){
            x-=2*i;
        }
        y/=10;
        i*=10;
    }
    return x;
}
int main (){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int m,n,x;
    cin>>m>>n;
    int a[m+1],k[2][n],kj=0;
    for(int i=1;i<=m;i++){
        cin>>a[i];
        a[i]=ER(a[i]);
    }
    for(int i=1;i<=m;i++){
        for(int j=i;j<=m;j++){
            x=a[i];
            for(int q=i+1;q<=j;q++){
                x=JIA(x,a[q]);
            }
            if(x==ER(n)){
                k[0][kj]=i;
                k[1][kj]=j;
                kj++;
            }
        }
    }

    for(int i=0;i<kj;i++){
        if(k[0][i]==0){
            continue;
        }
        for(int j=i+1;k[1][i]>=k[0][j];j++){
            k[0][j]=0;
            kj--;
        }
    }
    cout<<kj;
    return 0;
}

#include<iostream>
#include<bits/stdc++.h>
int we(int x,int y){
long long a[105],b[105],c[105],z=0,B;
    for(int i=1;;i++){
        if(x%2==0){
            a[i]=0;
        }
        else{
            a[i]=1;
        }
        if(x==1){

            B=i;
            break;
        }
        x/=2;

    }
    for(int i=1;;i++){
        if(y%2==0){
            b[i]=0;
        }
        else{
            b[i]=1;
        }
        if(y==1){
            if(B<i)
            B=i;
            break;
        }
        y/=2;
    }
    for(int i=B;i>=1;i--){
            if(a[i]!=b[i])
                c[i]=1;
            else
                c[i]=0;
    }
    for(int i=1;i<=B;i++){
        z+=c[i]*pow(2,i-1);
    }
    return z;
}long long d[10005],s,t=0,n,k;
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>d[i];
    }
s=d[1];
    for(int j=1;j<=n;j++){
        if(j==n)
            s+=we(d[j],0);
        else
            s+=we(s,d[j+1]);

            if(s==k){
                s=0;
                t++;
            }
        }
    cout<<t;
    return 0;
}

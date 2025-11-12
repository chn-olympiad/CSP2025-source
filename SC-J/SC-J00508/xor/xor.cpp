#include<bits/stdc++.h>
using namespace std;
long long a[500005],m,n,t,s,b[25],c[25];
int dick(int x,int y){
    for(int k=1;k<=20;k++){
        b[k]=0;
        c[k]=0;
    }
    int i=1,a1,a2;
    while(x>0){
        b[i]=x%2;
        x/=2;
        i++;
    }
    a1=i;
    i=1;
    while(y>0){
        c[i]=y%2;
        y/=2;
        i++;
    }
    a2=i;
    x=0;
    for(i=1;i<=max(a1,a2)-1;i++){
        if(b[i]!=c[i])b[i]=1;
        else if(b[i]==1)b[i]=0;
        else b[i]=1;
        x+=b[i]*pow(2,i-1);
    }
    return x;
}
int dickless(int x,int y){
    for(int k=1;k<=20;k++){
        b[k]=0;
        c[k]=0;
    }
    int i=1,a1,a2;
    while(x>0){
        b[i]=x%2;
        x/=2;
        i++;
    }
    a1=i;
    i=1;
    while(y>0){
        c[i]=y%2;
        y/=2;
        i++;
    }
    a2=i;
    x=0;
    for(i=1;i<=max(a1,a2)-1;i++){
        if(b[i]!=c[i])b[i]=1;
        else if(b[i]==1)b[i]=1;
        else b[i]=0;
        x+=b[i]*pow(2,i-1);
    }
    if(x==m)return 1;
    else return 0;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        a[i]=dick(a[i],a[i-1]);
    }
    for(int i=1;i<=n;i++){
        for(int j=t;j<i;j++){
            if(dickless(a[i],a[j])){
                s++;
                t=a[j];
            }
        }
    }
    cout<<s;
    return 0;
}

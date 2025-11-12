#include<bits/stdc++.h>
using namespace std;
freopen("club.in","r","stdin");
freopen("club.out"."w","stdout");
const int MAXN=10000,MINN=10000;
int t,n,m,ans,len,a[MAXN,MINN],b[MAXN];
int void clear(int a[i],j){
    for(int i=0;i<j;i++){
        a[i]=0;
    }
}
int void add(int a[MAXN,MINN],int b[MAXN]{
    if(a[MAXN,MINN]<a[MAXN+1,MINN]){
        b[MAXN]=a[MAXN+1,MINN];
        len++;
        m=n/2-len;
        return a[MAXN+1,MINN];
    }
    b[MAXN+1]=a[MAXN,MINN];
    len++;
    m=n/2-len;
    return 0;
}
int void mul(int a[MAXN,MINN],int b[MAXN]{
    if(a[MAXN,MINN]<a[MAXN,MINN+1]){
        b[MAXN]=a[MAXN,MINN+1];
        return a[MAXN,MINN+1];
    }
    b[MAXN]=a[MAXN,MINN+1];
    return 0;
}
int main(){
    cin>>t;
    for(int i;i<t;i++){
        cin>>n;
        for(int j=1;j<=n;j++){
            for(int k=1;k<=3;k++){
                cin>>a[j,k];
                for(int j=0;j<len;j++){
                    add(a[j,k],b[j]);
                    ans+=b[j];
                clear(b[j],j);
                }
                for(int j=0;j<len;j++){
                    mul(a[j,k],b[j]);
                    ans+=b[j];
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int s;
bool cmp(int x,int y){
if(x>y)return 1;
else
return 0;
}
int zhong(int w,int e,int r){
    int y;
    int m=max(w,max(e,r));
     if(m==w){
        y=m-max(e,r);
     }
     else if(m==e){
        y=m-max(w,r);
     }
     else if(m==r){
        y=m-max(w,e);
     }
 return y;
}
int main(){
    freopen("club4.in","r",stdin);
    freopen("club.out","w",stdout);
cin>>s;
for(int i=1;i<=s;i++){
long long a,c=0,m=0,n=1,b=1,v=1,p=1,o=1,u=1;
int d[100345];
int g[100345];
int h[100345];
int d1[100345];
int g1[100345];
int h1[100345];
int k[100345];


cin>>a;
for(int j=1;j<=a;j++){
        int w,e,r;
cin>>w>>e>>r;
    k[j]=zhong(w,e,r);
    d[j]=w;
    g[j]=e;
    h[j]=r;
}
sort(k+1,k+a+1,cmp);
for(int j=1;j<=a;j++){
    for(int z=1;z<=a;z++){
            int t=zhong(d[z],g[z],h[z]);

     if(t==k[j]){
        d1[j]=d[z];
        g1[j]=g[z];
        h1[j]=h[z];
        d[z]=-1;
        g[z]=-1;
        h[z]=-1;

    z=a+2;
     }
}
}
for(int j=1;j<=a;j++){
        if(p>a/2){
        d1[n]=-1;
    }
    if(o>a/2){
        g1[b]=-1;
    }
    if(u>a/2){
        h1[v]=-1;
    }
    m=max(d1[n],max(g1[b],h1[v]));

    c=c+m;


    if(d1[n]==m){
        p++;
    }
    else if(g1[b]==m){
        o++;
    }
    else if(h1[v]==m){
        u++;
    }
    n++;
    b++;
    v++;
}
cout<<c<<endl;
}


return 0;


}

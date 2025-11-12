#include<bits\stdc++.h>
using namespace std;
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
long long n;
int a;
int s;
int d;
int z[3000000];
int q[1000000];
int w[1000000];
int e[1000000];
int r;
int t;
int y;
int o;
int h[20000];
int main(){
for(int i=0;i<n;i++){
    cin >>q[i]>>w[i]>>e[i];
}
for(int i=0;i<n;i++){
    if(q[i]>w[i]  && q[i]>e[i]){
        r=q[i]+r;
        a++;
    }
    if(w[i]>q[i]  && w[i]>e[i]){
        t=w[i]+t;
        s++;
    }
    if(e[i]>w[i]  && q[i]<e[i]){
        y=e[i]+y;
        d++;
    }
}
if(2*a<=n && 2*s<=n && 2*d<=n){
    cout<<r+t+y;
}
else if(2*a>n){
    int p=a-n/2;
    for(int i=0;i<n;i++){
        if(q[i]-w[i]>q[i]-e[i]){
            o=q[i]-w[i];
        }
        else{
            o=q[i]-e[i];
        }
        h[i]=o;
    }
    sort(h,0,p);
    int n;
    for(int i=0;i<p;i++){
        n=n+h[p];
    }
    cout<<r+t+y-n;
}
else if(2*s>n){
    int p=s-n/2;
    for(int i=0;i<n;i++){
        if(w[i]-q[i]>w[i]-e[i]){
            o=w[i]-q[i];
        }
        else{
            o=w[i]-e[i];
        }
        h[i]=o;
        }
    sort(h,0,p);
    int n;
    for(int i=0;i<p;i++){
        n=n+h[p];
    }
    cout<<r+t+y-n;
}
else if(e*s>n){
    int p=d-n/2;
    for(int i=0;i<n;i++){
        if(e[i]-q[i]>e[i]-w[i]){
            o=e[i]-q[i];
        }
        else{
            o=e[i]-w[i];
        }
        h[i]=o;
    }
    sort(h,0,p);
    int n;
    for(int i=0;i<p;i++){
        n=n+h[p];
    }
    cout<<r+t+y-n;
}
return 0;
}

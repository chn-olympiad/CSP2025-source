#include<bits/stdc++.h>
using namespace std;
long long n,a[5001],p=0;
int san(int q,int w,int e){
    if(q+w+e>(max(max(q,w),e))*2){
        return 1;
    }
    else{
        return 0;
    }
}
int si(int q,int w,int e,int r){
    if(q+w+e+r>(max(max(q,w),max(e,r)))*2){
        return 1;
    }
    else{
        return 0;
    }
}
int wu(int q,int w,int e,int r,int t){
    if(q+w+e+r+t>(max(max(q,w),max(e,max(t,r))))*2){
        return 1;
    }
    else{
        return 0;
    }
}
int liu(int q,int w,int e,int r,int t,int y){
    if(q+w+e+r+t+y>(max(max(q,w),max(max(y,e),max(t,r))))*2){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==3){
        cout<<san(a[1],a[2],a[3]);
    }
    if(n==4){
        p+=san(a[1],a[2],a[3]);
        p+=san(a[1],a[2],a[4]);
        p+=san(a[1],a[3],a[4]);
        p+=san(a[2],a[3],a[4]);
        p+=si(a[1],a[2],a[3],a[4]);
        cout<<p;
    }
    if(n==5){
        p+=san(a[1],a[2],a[3]);
        p+=san(a[1],a[2],a[4]);
        p+=san(a[1],a[2],a[5]);
        p+=san(a[1],a[3],a[4]);
        p+=san(a[1],a[3],a[5]);
        p+=san(a[1],a[4],a[5]);
        p+=san(a[2],a[3],a[4]);
        p+=san(a[2],a[3],a[5]);
        p+=san(a[2],a[4],a[5]);
        p+=san(a[3],a[4],a[5]);
        p+=si(a[1],a[2],a[3],a[4]);
        p+=si(a[1],a[2],a[3],a[5]);
        p+=si(a[1],a[2],a[4],a[5]);
        p+=si(a[1],a[5],a[3],a[4]);
        p+=si(a[5],a[2],a[3],a[4]);
        p+=wu(a[1],a[2],a[3],a[4],a[5]);
        cout<<p;
    }
    if(n==6){
        p+=san(a[1],a[2],a[3]);
        p+=san(a[1],a[2],a[4]);
        p+=san(a[1],a[2],a[5]);
        p+=san(a[1],a[2],a[6]);
        p+=san(a[1],a[3],a[4]);
        p+=san(a[1],a[3],a[5]);
        p+=san(a[1],a[3],a[6]);
        p+=san(a[1],a[4],a[5]);
        p+=san(a[1],a[4],a[6]);
        p+=san(a[1],a[5],a[6]);
        p+=san(a[2],a[3],a[4]);
        p+=san(a[2],a[3],a[5]);
        p+=san(a[2],a[3],a[6]);
        p+=san(a[2],a[4],a[5]);
        p+=san(a[2],a[4],a[6]);
        p+=san(a[2],a[5],a[6]);
        p+=san(a[3],a[4],a[5]);
        p+=san(a[3],a[4],a[6]);
        p+=san(a[3],a[5],a[6]);
        p+=san(a[4],a[5],a[6]);
        p+=si(a[1],a[2],a[3],a[4]);
        p+=si(a[1],a[2],a[3],a[5]);
        p+=si(a[1],a[2],a[3],a[6]);
        p+=si(a[1],a[3],a[4],a[5]);
        p+=si(a[1],a[3],a[4],a[6]);
        p+=si(a[1],a[4],a[5],a[6]);
        p+=si(a[2],a[3],a[4],a[5]);
        p+=si(a[2],a[3],a[4],a[6]);
        p+=si(a[2],a[4],a[5],a[6]);
        p+=si(a[3],a[4],a[5],a[6]);
        p+=wu(a[1],a[2],a[3],a[4],a[5]);
        p+=wu(a[1],a[2],a[3],a[4],a[6]);
        p+=wu(a[1],a[2],a[3],a[6],a[5]);
        p+=wu(a[1],a[2],a[6],a[4],a[5]);
        p+=wu(a[1],a[6],a[3],a[4],a[5]);
        p+=wu(a[6],a[2],a[3],a[4],a[5]);
        p+=liu(a[1],a[2],a[3],a[4],a[5],a[6]);
        cout<<p;
    }
    return 0;
}

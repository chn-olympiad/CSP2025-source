#include<bits/stdc++.h>
using namespace std;
int n,m,cnt=1,a[200],k;
bool cmp(int a,int b){
    return a>b;
}
int c(int a,int b){
    double a1=a*1.0/b;
    int a2=a/b;
    if(a1-a2==0){
        return a2;
    }
    else{
        return a2+1;
    }
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>a[1];
    k=a[1];
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
        if(a[i]>k){
            cnt++;
        }
    }
    sort(a,a+n*m-1,cmp);
    int h,l;
    l=c(cnt,m);
    if(l%2==1){
        h=cnt%m;
        if(h==0){
            h=m;
        }
    }
    else{
        cnt%=n;
        h=(n-cnt+1)%n;
    }
    cout<<l<<" "<<h;
    return 0;
}

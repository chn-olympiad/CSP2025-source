#include<bits/stdc++.h>
using namespace std;
int n,m,b,a[105],R,r,h,l;
bool cmp(int a,int b){
return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    b=n*m;
    for(int i=0;i<b;i++){
        cin>>a[i];
    }
    R=a[0];
    sort(a,a+b,cmp);
    for(int i=0;i<b;i++){
        if(a[i]==R){
                r=i+1;
        break;
        }
    }
    if(r%n==0){
            l=r/n;
    if(l%2==0)h=1;
    else h=n;
    }
    else if(r%n!=0){l=r/n+1;
    if(l%2==0)h=n-r%n+1;
    else h=r%n;}
    cout<<l<<" "<<h;
return 0;
}

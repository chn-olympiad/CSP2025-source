#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n=0,m=0,b=0,c=0,d=0,e=0,f=0;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];b=a[1];
    }
    for(int i=1;i<=n*m;i++){
        if(a[i]>b) c++;
    }
    c++;
    if(c%n==0) d=c/n;
    else d=c/n+1;
    f=n-c%n;
    if(n%2==0){
        if(f==1) e=n;
        else e=n-f+1;
    }
    else e=c%n;


    cout<<d<<" "<<e<<endl;
    return 0;
}

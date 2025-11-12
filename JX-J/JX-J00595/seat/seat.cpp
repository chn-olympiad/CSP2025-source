#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
int n,m;
int s;
int t=0;
cin>>n>>m;
    for(int i=1;i<=(n*m);i++){
        cin>>a[i];
    }
    s=a[1];
    sort(a+1,a+1+(n*m));
    for(int i=n*m;i>=1;i--){
            t++;
        if(s==a[i]){
           break;
        }
    }
    int c;
    if(t%n==0)c=t/n;
    if(t%n!=0)c=((t/n)+1);
    int r;
    s=n;
    n=(n*(t/n));
    if(n==t)t=n;
    else t=(t-n);
    if(c%2==1){
       r=t;
    }
    else if(c%2==0){
       r=s-t+1;
    }
    cout<<c<<" "<<r;
    return 0;
}

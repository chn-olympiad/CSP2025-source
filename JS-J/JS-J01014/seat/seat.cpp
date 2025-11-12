#include<bits/stdc++.h>
using namespace std;
const int N=110;
int a1[N],a[N];
int main(){
    freopen("seat1.in","r",stdin);
    freopen("seat1.out","w",stdout);
    int m,n;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a1[i];
    }
    int x,y,s,p;
    s=a1[1];
    sort(a1+1,a1+1+n*m);
    for(int i=n*m;i>0;i--){
        a[n*m-i+1]=a1[i];
    }
    for(int i=1;i<=n*m;i++){
        if(a[i]==s){
            p=i;
            break;
        }
    }
    if(p%n==0){
        x=p/n;
    }
    else{
        x=p/n+1;
    }
    if(x%2==1){
        y=p-(x-1)*n;
    }
    else{
        y=n+1-(p-(x-1)*n);
    }
    cout<<x<<" "<<y;
    return 0;
}

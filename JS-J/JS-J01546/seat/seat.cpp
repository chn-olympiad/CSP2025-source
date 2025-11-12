#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,w=0,r=0;
    cin >> n >> m;
    int a[n*m+4];
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int b=a[1];
    for(int i=1;i<=n*m;i++){
        for(int j=i;j<=n*m;j++){
            if(a[i]<a[j]){
                int q=a[i];
                a[i]=a[j];
                a[j]=q;
            }
        }
    }
    for(int i=1;i<=n*m;i++){
        if(a[i]==b){
            w=i;
        }
    }
    if(w%n==0){
        if(w/n%2==0){
            r=0;
        }else{
            r=n;
        }
    }
    else if((w/n+1)%2==0){
        r=n+1-w%n;
    }
    else{
        r=w%n;
    }
    if(w%n==0){
        w/=n;
    }else{
        w=w/n+1;
    }
    cout <<w << " "<<r<<endl;
    return 0;
}
